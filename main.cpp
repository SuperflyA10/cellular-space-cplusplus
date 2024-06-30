#include <iostream>
#include <sstream>
#include "CellularSpace.h"

using namespace std;
using namespace CellularSpace;


int main(int argc, char* argv[])
{
    if(argc!=2) //error handling for arguments.
    {
        cerr << " Done. " << endl;
        exit(ERR_ARGC);
    }

    //pass the array the array length from the command line
    int arrlength=0;
    arrlength = string_to_int(argv[1]);

    //declaring variables
    int decision;
    int* new_Array = new int();
    srand(time(nullptr));
    int num=0;
    int num_Rounds=0;
    bool blncontinue = true;

    do{
        char Option;
        cout << "Option A: Start,Number of rounds. " << endl
             << "Option B: Generate first round. " << endl
             << "Option C: Generate cellular automata. " << endl
             << "Option X: End" << endl
             << "Select one of the options above: " << endl;
            cout << endl;

        cin >> Option;
        switch(Option)
        {
            case 'a':
            case 'A':
                cout << "Enter number of rounds for the automatan: " << endl;
                cin >> num_Rounds;
                if(cin.fail())
                {
                    cerr << "invalid number of rounds" << endl;
                    exit(ERR_NUM);
                }
                cout << "Number of rounds: " <<num_Rounds<< endl;
                cout << endl;
                break;

            case 'b':
            case 'B':
                cout << "Would you like to enter your own values or generate random  values? 1-Enter or 2-random." << endl;
                cin >> decision;
                if(cin.fail() || (decision!=1 && decision!=2))
                {
                    cout << "invalid input, only 1 or 2 is an acceptable input.";
                    //cerr << exit(ERR_DEC);
                }
                if(decision==1)
                    new_Array = gen_User_Array(arrlength,num); //generate user defined array
                else if (decision == 2)
                    new_Array = gen_Rand_Array(arrlength); //generate Random array

                cout << endl;
                break;

           case 'c':
            case 'C':
                gen_Automata(new_Array, num_Rounds,arrlength); //generate the cellular automate
                dealloc(new_Array); //deallocate the pointer array
                break;
                cout << endl;

            case 'x':
            case 'X':
                cout << "The end,hope you enjoyed the automation." << endl;
                blncontinue = false;
                break;

        }
    }while(blncontinue);

     return 0;
}
