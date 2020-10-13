#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

using namespace std;

class playing_space {                       // background
private:
    bool **space;
    int row;
    int col;
public:
    playing_space() : row(0), col(0) { }    // constructor
    playing_space(int ROW, int COL);
    ~playing_space();                       // deconstructor
    void print(ostream&);
    void drop(class block &BLK, int move_step);            // ~~~~~~~~~~~~~~~~~~~~~~~~~
    
    bool delete_check(int read_row);        // check when a row full of 1
    bool delete_row(int row_deleted);       // if a row full of 1, delete this row
    bool check_over();
};

class block {
private:
    friend playing_space;                   // block can use class playing_space's member
protected:
    int stop_size;
    int *lowest_block_position;             // when lowest_block_position[a] = b
                                            // it means there has b rooms (space) can put in
                                            // column a
                                            // i.e lower_block_position[2] = 2
                                            // column 2 has 2 white space

    int block_position[4][2];               // can expand when needed
    int initial_position;                   // input position

    int now_row;                            // at this time, row is which one
public:
    virtual ~block() { }
    int get_now_row() {
        return now_row;
    }
};


class T_block:public block{
    public:
    T_block(){}
    T_block(int initial_place, int type);
    ~T_block();

};


class L_block:public block{
    public:
    L_block(){}
    L_block(int initial_place, int type);
    ~L_block();
};



class J_block:public block{
    public:
    J_block(){}
    J_block(int initial_place, int type);
    ~J_block();
};

class S_block:public block{
    public:
    S_block(){}
    S_block(int initial_place, int type);
    ~S_block();
};

class Z_block:public block{
    public:
    Z_block(){}
    Z_block(int initial_place, int type);
    ~Z_block();
};

class I_block:public block{
    public:
    I_block(){}
    I_block(int initial_place, int type);
    ~I_block();
};

class O_block:public block{
    public:
    O_block(){}
    O_block(int initial_place);
    ~O_block();
};
////////// start of T_block     ///////////////////


T_block::T_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 1;
        lowest_block_position[1] = 0;
        lowest_block_position[2] = 1;

        block_position[0][0] = 0; block_position[0][1] = 1;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 1; block_position[3][1] = 2;
    }
    else if (type == 2)
    {
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 1;
        lowest_block_position[1] = 0;

        block_position[0][0] = 0; block_position[0][1] = 1;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 2; block_position[3][1] = 1;
    }
    else if (type == 3)
    {
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 0;
        lowest_block_position[2] = 0;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 0; block_position[1][1] = 1;
        block_position[2][0] = 0; block_position[2][1] = 2;
        block_position[3][0] = 1; block_position[3][1] = 1;
    }
    else if (type == 4)
    {
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 1;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 2; block_position[3][1] = 0;
    }
    else {
        cout << "invalid input!!" << endl;
    }
}
T_block::~T_block(){delete lowest_block_position;}

    // end of the definition of T_block

    // start of the definition of L_block

L_block::L_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 0;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 0; block_position[1][1] = 1;
        block_position[2][0] = 1; block_position[2][1] = 0;
        block_position[3][0] = 2; block_position[3][1] = 0;
    }
    else if (type == 2)
    {
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 1;
        lowest_block_position[2] = 1;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 1; block_position[3][1] = 2;
    }
    else if (type == 3)
    {
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 2;
        lowest_block_position[1] = 0;

        block_position[0][0] = 0; block_position[0][1] = 1;
        block_position[1][0] = 1; block_position[1][1] = 1;
        block_position[2][0] = 2; block_position[2][1] = 0;
        block_position[3][0] = 2; block_position[3][1] = 1;
    }
    else if (type == 4)
    {
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 0;
        lowest_block_position[2] = 0;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 0; block_position[1][1] = 1;
        block_position[2][0] = 0; block_position[2][1] = 2;
        block_position[3][0] = 1; block_position[3][1] = 2;
    }
    else cout << "invalid input!!" << endl;

}
L_block::~L_block(){delete lowest_block_position;}

    // end of the definition of L_block

    // start of the definition of J_block

J_block::J_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 0;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 0; block_position[1][1] = 1;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 2; block_position[3][1] = 1;
    }
    else if (type == 2)
    {
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 0;
        lowest_block_position[2] = 0;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 0; block_position[1][1] = 1;
        block_position[2][0] = 0; block_position[2][1] = 2;
        block_position[3][0] = 1; block_position[3][1] = 0;
    }
    else if (type == 3)
    {
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 2;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 2; block_position[2][1] = 0;
        block_position[3][0] = 2; block_position[3][1] = 1;
    }
    else if (type == 4)
    {
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 1;
        lowest_block_position[1] = 1;
        lowest_block_position[2] = 0;

        block_position[0][0] = 0; block_position[0][1] = 2;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 1; block_position[3][1] = 2;
    }
    else cout << "invalid input!!" << endl;

}
J_block::~J_block(){delete lowest_block_position;}

    // end of the definition of J_block

    // start of the definition of S_block

S_block::S_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 0;
        lowest_block_position[2] = 1;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 0; block_position[1][1] = 1;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 1; block_position[3][1] = 2;
    }
    else if (type == 2)
    {
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 1;
        lowest_block_position[1] = 0;

        block_position[0][0] = 0; block_position[0][1] = 1;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 2; block_position[3][1] = 0;
    }
    else cout << "invalid input!!" << endl;

}
S_block::~S_block(){delete lowest_block_position;}

    // end of the definition of S_block

    // start of the definition of Z_block

Z_block::Z_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 3;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 1;
        lowest_block_position[1] = 0;
        lowest_block_position[2] = 0;

        block_position[0][0] = 0; block_position[0][1] = 1;
        block_position[1][0] = 0; block_position[1][1] = 2;
        block_position[2][0] = 1; block_position[2][1] = 0;
        block_position[3][0] = 1; block_position[3][1] = 1;
    }
    else if (type == 2)
    {
        stop_size = 2;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 1;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 1; block_position[2][1] = 1;
        block_position[3][0] = 2; block_position[3][1] = 1;
    }
    else cout << "invalid input!!" << endl;

}
Z_block::~Z_block(){delete lowest_block_position;}

    // end of the definition of Z_block

    // start of the definition of I_block

I_block::I_block(int initial_place, int type){
    
    now_row = 3;
    initial_position= initial_place;
    
    if (type == 1)
    {        
        stop_size = 1;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 1; block_position[1][1] = 0;
        block_position[2][0] = 2; block_position[2][1] = 0;
        block_position[3][0] = 3; block_position[3][1] = 0;
    }
    else if (type == 2)
    {
        stop_size = 4;
        lowest_block_position = new int[stop_size];
        lowest_block_position[0] = 0;
        lowest_block_position[1] = 0;
        lowest_block_position[2] = 0;
        lowest_block_position[3] = 0;

        block_position[0][0] = 0; block_position[0][1] = 0;
        block_position[1][0] = 0; block_position[1][1] = 1;
        block_position[2][0] = 0; block_position[2][1] = 2;
        block_position[3][0] = 0; block_position[3][1] = 3;
    }
    else cout << "invalid input!!" << endl;

}
I_block::~I_block(){delete lowest_block_position;}

    // end of the definition of I_block

    // start of the definition of O_block

O_block::O_block(int initial_place){
    
    now_row = 3;
    initial_position= initial_place;

    stop_size = 2;
    lowest_block_position = new int[stop_size];
    lowest_block_position[0] = 0;
    lowest_block_position[1] = 0;

    block_position[0][0] = 0; block_position[0][1] = 0;
    block_position[1][0] = 0; block_position[1][1] = 1;
    block_position[2][0] = 1; block_position[2][1] = 0;
    block_position[3][0] = 1; block_position[3][1] = 1;

}
O_block::~O_block(){delete lowest_block_position;}

    // end of the definition of O_block

//////////////// begin of the definition of playing_space //////////////////////////

playing_space::playing_space(int ROW, int COL) : row(ROW+4), col(COL) {
    space = new bool* [row];                        // row 個 pointer, form a (row+4) * col background
    for (int i = 0; i < row; ++i) {
            space[i] = new bool [COL];
            cout << "set in the funcion playing space , 493" << endl;
    }
    cout << row << " " << col << endl;
    for (int i = 0; i < row; ++i) {                 // set all value 0
        for (int j = 0; j < COL; ++j) {
            space[i][j] = 0;
        }
                        
    }
    cout << "set in the funcion playing space , finish" << endl;
}
playing_space::~playing_space() {                   // deconstructor
    for (int i = 0; i < row; ++i) {
        delete space[i];
    }
    delete space;
}
void playing_space::drop(block &BLK, int move) {
    bool stop = false;
    int inspect = BLK.now_row;
    
    for (int i = BLK.now_row; (i < row - 1) && (!stop); i++)                // first time drop
    { 
        for (int j = 0; (j < BLK.stop_size) && (!stop); ++j)
        {
            if (space[i - BLK.lowest_block_position[j] + 1][BLK.initial_position + j])
                stop = true;
        }
        if (!stop) BLK.now_row++;
    }
    
    
    stop = false;
    for (int i = BLK.now_row; (i < row - 1 ) && (!stop); i++)               // second time drop
    { 
        for (int j = 0; (j < BLK.stop_size) && (!stop); ++j)
        {
            if (space[i - BLK.lowest_block_position[j] + 1][BLK.initial_position + move + j])
                stop = true;
        }
        if (!stop) BLK.now_row++;
    } 
    
    
	for (int i = 0; i < 4; ++i)
        space[BLK.now_row - BLK.block_position[i][0]][BLK.initial_position + move + BLK.block_position[i][1]] = true;

}
bool playing_space::check_over(){
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < col; ++j)
            if (space[i][j]) return true;
    return false;
}
bool playing_space::delete_check(int read_row) {
    int sum = 0;
    for (int i = 0; i < col; ++i) {                 // sum this row's element
        sum += space[read_row][i];
    }
    if (sum == col) return true;                    // if sum == col, it means all element is 1
    else return false;                              // sum != col
}

bool playing_space::delete_row(int row_deleted){
    bool delete_done = false;
    if (delete_done = delete_check(row_deleted))
    {
        for (int i  = row_deleted; i >= 1; --i)
            for (int j = 0; j < col; ++j)
                space[i][j] = space[i - 1][j];
    }
    for (int i = 0; i < col; ++i)
        space[0][i] = false;
    return delete_done;
}
void playing_space::print(ostream& file_out) {
    
    char *arr;
    arr = new char[col + 1];
    
    for (int i = 4; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (space[i][j]) {
                arr[j] = '1';
            } else {
                arr[j] = '0';
            }
        }
        arr[col] = '\n';
        file_out.write(arr, col + 1);           // write(memory_block, size);
    }
    
}


////////// end of playing_space ///////////////////




int main(int argc, char **argv)
{
    int row, col;
    ifstream file_in;
    ofstream file_out;

    file_in.open(argv[1], ios::in);
    file_out.open(argv[2], ios::out | ios::trunc);
    cout << "good597" << endl;
    if (!file_in.is_open())
    {
        cout << "Open file fails!\n";
        return 0;
    } else {
        cout << "open!!" << endl;
    }
    if(!file_out.is_open()) {
        cout << "open out_file fails!\n";
        return -1;
    } else {
        cout << "open out OK !" << endl;
    }

    file_in >> row >> col;

    cout << "time to set row col" << endl;
    playing_space space(row, col);
    cout << "set finish " << endl;

    cout << "good606" << endl;
    char ch[50];
    int begin;
    int move_step;					// new
    bool game_over = false;
    file_in >> ch;
    while (strcmp(ch, "End") && !game_over)
    {    
        char type;
        int type_number;
        cout << "good616" << endl;
        if (ch[0] != 'O') {
            type_number = atoi(&ch[1]);
            type = ch[0];
        }
        else type = ch[0];

        file_in >> begin;
        file_in >> move_step;		// new
        begin--;
        block *B;
		cout << "good627" << endl;
        if (!game_over)									
        {   
            if (type == 'T')     
                B = new T_block(begin, type_number);
            else if (type == 'L')
                B = new L_block(begin, type_number);
            else if (type == 'J')
                B = new J_block(begin, type_number); 
            else if (type == 'S')
                B = new S_block(begin, type_number); 
            else if (type == 'Z')
                B = new Z_block(begin, type_number); 
            else if (type == 'I')
                B = new I_block(begin, type_number); 
            else
                B = new O_block(begin);
            space.drop(*B, move_step);
            for (int j = 0, k = 0; j < 4; ++j)
            {    
                if (B->get_now_row() - k >= 4 && space.delete_row(B->get_now_row() - k));
                else k++;
            }
            game_over = space.check_over();				// check if all scatter the ground
            delete B;
        }

        if (!game_over) file_in >> ch;
    }
    cout << "good656" << endl;
    
    space.print(file_out);                  // print it to file_out
    cout << "good663" << endl;
    file_in.close();                        // ensure file_in close
    if (file_in.is_open())
    {
        cout << "Close file fails!\n";
        return 0;
    }
    file_out.close();                       // ensure file_out close
    if (file_out.is_open()) {
        cout << "close out_file fails!\n";
    }
    return 0;
}

