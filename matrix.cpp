// Angelina Loayza - CMSC 313                                                                          
// 16 April 2025                                                                                       
#include <iostream>
#define ROWS 2
#define COLS 2
#define B_ROWS 2
#define B_COLS 3
#define C_ROWS 2
#define C_COLS 3
#define DEFAULT_RETURN_VALUE 0
using namespace std;

class MatrixFunctions{
public:
  //Constructors and destructors                                                                       
  MatrixFunctions(int userRowSize, int userColumnSize){
    row_size = userRowSize;
    column_size = userColumnSize;
  }

  //Data Members                                                                                       
  int row_size;
  int column_size;

  //Function Members                                                                                   
  void addMatrices(int result[ROWS][COLS], int mat1[ROWS][COLS], int mat2[ROWS][COLS]){
    for(int i=0; i<row_size; i++){
      for(int j=0; j<column_size; j++)
        result[i][j] = mat1[i][j]+mat2[i][j];
    }
  }
  void transposeMatrix(int result[C_COLS][C_ROWS], int mat[C_ROWS][C_COLS]){
    for(int i=0; i<C_ROWS; i++){
      for(int j=0; j<C_COLS; j++)
        result[j][i] = mat[i][j];
    }
  }
  void scalarMultiply(int result[B_ROWS][B_COLS], int mat[B_ROWS][B_COLS], int c){
    for(int i=0; i<B_ROWS; i++){
      for(int j=0; j<B_COLS; j++)
        result[i][j] = mat[i][j]*c;
    }
  }
  void multiplyMatrices(int result[ROWS][COLS], int mat1[B_ROWS][B_COLS], int mat2[C_COLS][C_ROWS]){
    for(int i=0; i<ROWS; i++){
      for(int j=0; j<COLS; j++){
        result[i][j]=0;
        for(int k=0; k<B_COLS; k++)
          result[i][j]+= mat1[i][k]*mat2[k][j];
      }
    }
  }
  void printMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < row_size; ++i) {
      for (int j = 0; j < column_size; ++j)
        cout << mat[i][j] << " ";
      cout << endl;
    }
  }
};

int main(){
  int A[ROWS][COLS] = { {6, 4}, {8, 3} };
  int B[B_ROWS][B_COLS] = { {1, 2, 3}, {4, 5, 6} };
  int C[C_ROWS][C_COLS] = { {2, 4, 6}, {1, 3, 5} };

  int First[B_ROWS][B_COLS]; //First calculation                                                       
  int Second[C_COLS][C_ROWS]; //Second calculation                                                     
  int Third[ROWS][COLS]; //Third calculation                                                           
  int D[ROWS][COLS]; //Final calculation                                                               

  MatrixFunctions calc(ROWS, COLS);

  calc.scalarMultiply(First, B, 3); //(3*B)                                                            
  calc.transposeMatrix(Second, C); //C^T                                                               
  calc.multiplyMatrices(Third, First, Second); //(3*B)xC^T                                             
  calc.addMatrices(D, A, Third); //A+(3*B)xC^T                                                         

  cout << "Resulting matrix D:" << endl;
  calc.printMatrix(D);
  return DEFAULT_RETURN_VALUE;
}
