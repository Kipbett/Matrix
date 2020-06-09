import java.util.Random;
import java.util.Scanner;

public class Matrix {

    static int arr1[][] = new int[100][100];
    static int arr2[][] = new int[100][100];
    static int arr3[][] = new int[100][100];
    static int row;
    static int column;

    public static void main(String[] args) {

        final long starttime = System.nanoTime();

        Random rand = new Random();

        Scanner input = new Scanner(System.in);

        System.out.println("Enter the number of rows: ");
        row = input.nextInt();

        System.out.println("Enter the number of column: ");
        column = input.nextInt();

        //System.out.println("Enter values for matrix 1");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                //System.out.print("[" + i + "] [" + j + "] : ");
                arr1[i][j] = rand.nextInt(100);
            }
        }

        //System.out.println("Enter values for matrix 2");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                //System.out.print("[" + i + "] [" + j + "] : ");
                arr2[i][j] = rand.nextInt(100);
            }
        }

        System.out.println("Values for matrix 1");

        for(int i = 0; i < row; i++){
            System.out.println("\n");
            for(int j = 0; j < column; j++){
                System.out.print(arr1[i][j]+"\t");
            }
        }

        System.out.println("\n");

        System.out.println("Values for matrix 2");

        for(int i = 0; i < row; i++){
            System.out.println("\n");
            for(int j = 0; j < column; j++){
                System.out.print(arr1[i][j]+"\t");
            }
        }

        int option;

        do{

            System.out.println("====================== SELECT AN OPTION ====================");
            System.out.println("1 : \t ADDITION OPERATION");
            System.out.println("2 : \t SUBTRACTION OPERATION");
            System.out.println("3 : \t MULTIPLICATION OPERATION");
            System.out.println("4 : \t EXIT OPERATION");

            System.out.print("Enter Your Option");
            option = input.nextInt();

            switch (option) {
                case 1:
                    addition();
                    break;

                case 2:
                    subtraction();
                    break;

                case 3:
                    multiplication();
                    break;

                case 4:
                    break;

                default:
                    System.out.println("INVALID INPUT. TRY AGAIN!!!");
                    break;
            }

        } while (option != 4);

        System.out.println("\n");

        final long duration = (System.nanoTime() - starttime)/1000000000;
        System.out.println("The system run for" + duration + " sec.");

    }

    public static void addition() {

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr3[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

        System.out.println("The result for addition is: ");
        for(int i = 0; i < row; i++){
            System.out.println("");
            for(int j = 0; j < column; j++){
                System.out.print(arr3[i][j]+"\t");
            }
        }

        System.out.println("");
    }

    public static void multiplication() {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr3[i][j] = 0;
                for(int k = 0; k < row; k++){
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

        System.out.println("The result for multiplication is: ");
        for(int i = 0; i < row; i++){
            System.out.println("");
            for(int j = 0; j < column; j++){
                System.out.print(arr3[i][j]+"\t");
            }
        }

        System.out.println("");
    }

    public static void subtraction() {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                arr3[i][j] = arr1[i][j] - arr2[i][j];
            }
        }

        System.out.println("The result for subtraction is: ");
        for(int i = 0; i < row; i++){
            System.out.println("");
            for(int j = 0; j < column; j++){
                System.out.print(arr3[i][j]+"\t");
            }
        }

        System.out.println("");
    }
}
