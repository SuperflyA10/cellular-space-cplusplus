#include "CellularSpace.h"


namespace CellularSpace

{
    int string_to_int(string str) //converting a string vsriable into an integer
    {
        int num=0;
        std::stringstream ss {str};
        ss >> num;

        if(ss.fail()) //error handling for ss stream
        {
            cout << "Could not covert " << str << " to integer." << endl;
            exit(ERR_SIZE);
        }

        return num;
    }

    int genRand() //generating 0 or 1 at random
    {
        int result;
        result = rand()%2;
        return result;
    }

    int* gen_User_Array(int Arraysize, int Array_num) //generating user defined array of 0's and 1's
    {
        int *arr = new int[Arraysize]; //intializing the array and setting the array size.
        for(int i=0; i<Arraysize;i++)
        {
            //User to fill the array with 0's and 1's
            cout << "Enter 0 or 1 for array value " << i+1 << endl;
            cin >> Array_num;

            if(cin.fail() || (Array_num!=1 && Array_num !=0))
            {
                cerr << "Invalid array value, only 0 and 1 is an acceptable input." << endl;
                exit(ERR_ARR);
            }
            arr[i] = Array_num;
        }

        //displaying the user defined array
        cout << "Round 1: " << endl;
        for(int i=0; i<Arraysize;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout << endl << endl;
        return arr;
    }

    int* gen_Rand_Array(int Arraysize) //Randomly generated array
    {
        int *arr = new int[Arraysize]; //intializing the array and setting the array size.
        for(int i=0; i<Arraysize;i++)
        {
            arr[i] = genRand(); //storing 0's and 1's at random in the array
        }

        //displaying the random array
        cout << "Round 1: " << endl;
        for(int i=0; i<Arraysize;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout << endl << endl;
        return arr;
    }


    void gen_Automata(int* &Array, int round,int Arraysize) //generate rule 30 automata
    {
        int* temp = new int[Arraysize];
        int first=0,second=0,third=0;

        cout << "Round 1: " << endl; //display the first round of cellular automata
        for(int i=0; i<Arraysize;i++)
        {
            cout<<Array[i]<<" ";
        }
        cout << endl;
        for(int n=0; n<round-1; n++)
        {
            for(int x=0;x<Arraysize; x++)
            {
                first = Array[x-1];
                second=Array[x];
                third=Array[x+1];

                if(x==0)
                    first = Array[Arraysize-1];
                if(x==Arraysize)
                    third = Array[0];

                if(first==1 && second==1 && third==1)
                    temp[x]=0;
                else if(first==1 && second==1 && third==0)
                    temp[x]=0;
                else if(first==1 && second==0 && third==1)
                    temp[x]=0;
                else if(first==1 && second==0 && third==0)
                    temp[x]=1;
                else if(first==0 && second==1 && third==1)
                    temp[x]=1;
                else if(first==0 && second==1 && third==0)
                    temp[x]=1;
                else if(first==0 && second==0 && third==1)
                    temp[x]=1;
                else if(first==0 && second==0 && third==0)
                    temp[x]=0;
            }

            for(int k=0;k<Arraysize;k++)
            {
                Array[k]=temp[k];
            }
            //Array = temp;
            cout << "Round: " << n+2 << endl;
            for(int z=0;z<Arraysize;z++)
            {
                cout << Array[z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void dealloc(int* &Array) //deallocate memory
    {
        delete[] Array;
        Array = nullptr;
    }
}
