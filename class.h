#ifndef CLASS_H
#define CLASS_H

#include <iostream>
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
    void print();
    void drop(~~~);
    
    bool delete_check(int read_row);        // check when a row full of 1
    bool delete_row(int row_deleted);       // if a row full of 1, delete this row
};

class block {
private:
    friend playing_space;                   // block can use class playing_space's member
protected:
    int stop_size;
    int *lower_block_position;              // when lowest_block_position[a] = b
                                            // it means there has b rooms (space) can put in
                                            // column a
                                            // i.e lower_block_position[2] = 2
                                            // column 2 has 2 white space

    int block_position[4][2];               // can expand when needed
    int initial_position;                   // input position
public:
    virtual ~block() { }
    int get_now_row();
};

class T_block::public block {               // T_block derived from class block
    T_block() { }
    T_block(int initial_place, int type);
    ~T_block() { }
};

class L_block::public block {               // L_block derived from class block
    L_block() { }
    L_block(int initial_place, int type);
    ~L_block() { }
};

class J_block::public block {               // J_block derived from class block
    J_block() { }
    J_block(int initial_place, int type);
    ~J_block() { }
};
class S_block::public block {               // S_block derived from class block
    S_block() { }
    S_block(int initial_place, int type);
    ~S_block() { }
};
class Z_block::public block {               // Z_block derived from class block
    Z_block() { }
    Z_block(int initial_place, int type);
    ~Z_block() { }
};
class I_block::public block {               // I_block derived from class block
    I_block() { }
    I_block(int initial_place, int type);
    ~I_block() { }
};
class O_block::public block {               // O_block derived from class block
    O_block() { }
    O_block(int initial_place, int type);
    ~O_block() { }
};

#endif