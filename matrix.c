// Angelina Loayza - CMSC 313                                                                          
// 16 April 2025                                                                                       
#include <stdio.h>
#define ROWS 2
#define COLS 2
#define B_ROWS 2
#define B_COLS 3
#define C_ROWS 2
#define C_COLS 3
#define CONSTANT 3
#define DEFAULT_RETURN_VALUE 0

int main(){
  int A[ROWS][COLS] = { {6, 4}, {8, 3} };
  int B[B_ROWS][B_COLS] = { {1, 2, 3}, {4, 5, 6} };
  int C[C_ROWS][C_COLS] = { {2, 4, 6}, {1, 3, 5} };
  int CT[C_COLS][C_ROWS];
  int D[ROWS][COLS];

  //(3*B)                                                                                              
  for(int i=0; i<B_ROWS; i++){
    for(int j=0; j<B_COLS; j++)
      B[i][j]= CONSTANT*B[i][j];
  }
  //C^T                                                                                                
  for(int k=0; k<C_ROWS; k++){
    for(int l=0; l<C_COLS; l++)
      CT[l][k]=C[k][l];
  }
  //(3*B)xC^T                                                                                          
  for(int a=0; a<ROWS; a++){
    for(int b=0; b<COLS; b++){
      D[a][b]=0;
      for(int c=0; c<B_COLS; c++)
        D[a][b]+=B[a][c]*CT[c][b];
    }
  }
  //A+(3*B)xC^T                                                                                        
  for(int d=0; d<ROWS; d++){
    for(int e=0; e<COLS; e++)
      D[d][e]+=A[d][e];
  }
  //Print                                                                                              
  printf("Resulting matrix D:\n");
  for(int f=0; f<ROWS; f++) {
    for(int g=0; g<COLS; g++)
      printf("%d ", D[f][g]);
    printf("\n");
  }

  return DEFAULT_RETURN_VALUE;
}
