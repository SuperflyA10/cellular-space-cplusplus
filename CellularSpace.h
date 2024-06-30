#ifndef CellularSpace_H
#define CellularSpace_H

#include <iostream>
#include <random>
#include <cmath>
#include <sstream>
#include <time.h>

using namespace std;

namespace CellularSpace
{
    const int ERR_NUM = -1;
    const int ERR_SIZE = -2;
    const int ERR_ARR = -3;
    const int ERR_DEC = -4;

    int string_to_int(std::string str);
    const int ERR_ARGC = -1;

    int genRand();
    int* gen_Rand_Array(int Arraysize);
    int* gen_User_Array(int Arraysize,int Array_num);
    void gen_Automata(int* &Array, int round,int Arraysize);
    void dealloc(int* &Array);
}

#endif // CellularSpace_H
