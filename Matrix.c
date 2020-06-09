#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add();
void subtraction();
void multiply();

int arr[100][100],arr2[100][100], arr3[100][100]; 
int i, j, k;
int choice;
int row, column;

int main(){

    clock_t start = clock();

    srand(time(0));

    printf("Enter the size of row: ");
    scanf("%d", &row);

    printf("Enter the size of column: ");
    scanf("%d", &column);


    //Enter the first matrix1

    for(i=0; i<row; i++){
        for ( j = 0; j < column; j++)
        {
            arr[i][j] = (rand()%100);
        }
        
    }

    //Enter the second matrix

    for(i=0; i<row; i++){
        for ( j = 0; j < column; j++)
        {
            arr2[i][j] = (rand()%100);
        }
        
    }

    printf("Elements of the array one: \n");

    for ( i = 0; i < row; i++)
    {
        printf("\n");
        for ( j = 0; j < column; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        
    }

    printf("\n");

    printf("Elements of the array two: \n");

    for ( i = 0; i < row; i++)
    {
        printf("\n");
        for ( j = 0; j < column; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        
    }
    
    printf("\n");

    do
    {
        printf("--------- ENTER A NUMBER TO SELECT THE OPERATION ----------- \n");
        printf("1 :     MATRIX ADDITION \n");
        printf("2 :     MATRIX SUBTRACTION \n");
        printf("3 :     MATRIX MULTIPLICATION\n");
        printf("4 :     EXIT \n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add();
            break;

        case 2:
            subtraction();
            break;

        case 3:
            multiply();
            break;

        case 4:
            break;
        
        default:
            printf("INVALID OPTION. TRY AGAIN!!!");
            break;
        }
    } while (choice != 4);
    
    printf("\n"); 

    clock_t end = clock();
    printf("Elapsed: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC); 
}

void multiply(){

    printf("Multiplication of the arrays:\n");

    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < column; j++)
        {
            arr3[i][j] = 0;
            for ( k = 0; k < row; k++)
            {
                arr3[i][j] += arr[i][k]*arr2[k][j];
            }
        }
    }

    printf("Result: \n");

    for ( i = 0; i < row; i++)
    {
        printf("\n");
        for ( j = 0; j < row; j++)
        {
            printf("%d\t", arr3[i][j]);
        }
    }

    printf("\n");
}

void add(){

    printf("Addition of the arrays:\n");

    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < column; j++)
        {
            arr3[i][j] = arr[i][j] + arr2[i][j];    
        }
    }

    printf("Result: \n");

    for ( i = 0; i < column; i++)
    {
        printf("\n");
        for ( j = 0; j < row; j++)
        {
            printf("%d\t", arr3[i][j]);
        }
    }

    printf("\n");
}

void subtraction(){

    printf("Subtraction of the Matrix:\n");

    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < column; j++)
        {
            arr3[i][j] = arr[i][j] - arr2[i][j];
        }
    }

    printf("Result: \n");

    for ( i = 0; i < row; i++)
    {
        printf("\n");
        for ( j = 0; j < column; j++)
        {
            printf("%d\t", arr3[i][j]);
        } 
    }

    printf("\n");
}
