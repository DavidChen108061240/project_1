#include <fstream>
#include "class.h"

//////////////// begin of the definition of playing_space //////////////////////////

playing_space::playing_space(int ROW, int COL) : row(ROW+4), col(COL) {
    space = new bool* [row];                        // row 個 pointer, form a row * col background
    for (int i = 0; i < row; ++i) {
            space[i] = new bool [COL];
    }
    for (int i = 0; i < row; ++i) {                 // set all value 0
        for (int j = 0; i < COL; ++j) {
            space[i][j] = 0;
        }
    }
}
playing_space::~playing_space() {                   // deconstructor
    for (int i = 0; i < row; ++i) {
        delete space[i];
    }
    delete space;
}
void playing_space::drop(block &BLK) {
    ////////////////////////////////
    
    
    /////////////////////////////////////////
}

bool playing_space::delete_check(int read_row) {
    int sum = 0;
    for (int i = 0; i < col; ++i) {                 // sum this row's element
        sum += space[read_row][i];
    }
    if (sum == col) return true;                    // if sum == col, it means all element is 1
    else return false;                              // sum != col
}
bool playing_space::delete_row(int row_deleted) {
    bool delete_done = false;
    if (delete_done = ....)

    //


}

void playing_space::print() {
    fstream file;
    char *arr;
    arr = new char[col + 1];
    file.open("108061240_prog_1.final", ios::out | ios::trunc);

    if(!file.is_open()) {
        cout << "close file fails!\n";
        return;
    }
    for (int i = 4; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (space[i][j]) {
                arr[j] = '1';
            } else {
                arr[j] = '0';
            }
        }
        arr[col] = '\n';
        file.write(arr, col + 1);           // write(memory_block, size);
    }
    file.close();
    if (file.is_open()) {
        cout << "close file fails!\n";
    }
}

////////// end of playing_space ///////////////////

////////// start of block       ///////////////////
int block::get_now_row() {
    return now_row;                         // get access of now_row
}
////////// end of block         ///////////////////

////////// start of T_block     ///////////////////
