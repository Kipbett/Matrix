#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class matrixc
{
private:
    int **arr1 = new int*[100];
    int **arr2 = new int*[100];
    int arr3[100][100];
    int row, column;
public:
    void enterData(){
        //Initiate the random numbers
        srand(time(0));

        for(int count = 0; count < 100; count++){
            arr1[count] = new int[100];
        }

        for(int count = 0; count < 100; count++){
            arr2[count] = new int[100];
        }

        cout << "Enter the number of rows: ";
        cin >> row;

        cout << "Enter the number of columns";
        cin >> column;

        //Randomly enter values for the first matrix

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr1[i][j] = (rand()%100);
            }
        }

        //Randomly enter values for the second matrix

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr2[i][j] = (rand()%100);
            }
        }

        cout << "\n";

        cout << "Display values for the first matrix; \n";

        for(int i = 0; i < row; i++){
            cout << "\n";
            for(int j = 0; j < column; j++){
                cout << arr1[i][j] << "\t";
            }
        }

        cout << "\n";

        cout << "Display values for the second matrix; \n";

        for(int i = 0; i < row; i++){
            cout << "\n";
            for(int j = 0; j < column; j++){
                cout << arr2[i][j] << "\t";
            }
        }

        cout << "\n";
    }

    void operator+ (){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr3[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

        cout << "The result of the addition is: \n";

        for(int i = 0; i < row; i++){
            cout << "\n";
            for(int j = 0; j < column; j++){
                cout << arr3[i][j] << "\t";
            }
        }

        cout << "\n";
    }

    void operator-(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr3[i][j] = arr1[i][j] - arr2[i][j];
            }
        }

        cout << "The result of the subtraction is: \n";

        for(int i = 0; i < row; i++){
            cout << "\n";
            for(int j = 0; j < column; j++){
                cout << arr3[i][j] << "\t";
            }
        }

        cout << "\n";
    }

    void operator*(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr3[i][j] = 0;
                for(int k = 0; k < row; k++){
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

        cout << "The result of the multiplication is: \n";

        for(int i = 0; i < row; i++){
            cout << "\n";
            for(int j = 0; j < column; j++){
                cout << arr3[i][j] << "\t";
            }
        }

        cout << "\n";
    }
};

int main(){

    auto start = high_resolution_clock::now();

    matrixc mc;

    mc.enterData();

    int option;

    do{
        cout << "------------------- SELECT AN OPTION --------------------- \n";
        cout << "1: \t ADDITION OPERATION \n";
        cout << "2: \t SUBTRACTION OPERATION \n";
        cout << "3: \t MULTIPLICATION OPERATION \n";
        cout << "4: \t EXIT OPERATION \n";

        cout << "ENTER YOUR OPTION";
        cin >> option;

        switch (option)
        {
        case 1:
            +mc;
            break;

        case 2:
            -mc;
            break;

        case 3:
            *mc;
            break;

        case 4:
            break;
        
        default:
            cout << "INVALID CHOICE. TRY AGAIN!!! \n";
            break;
        }
    } while (option != 4);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    cout << duration.count() << "\n";

    return 0;
    
}
