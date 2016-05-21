// ガウスの消去法で連立方程式Ax=bを解く
// Aの(i,j)成分は，1/((i+j-1)**2)
// Aは縦横SIZEの正方行列
// bはすべての要素が1

#include <iostream>
#include <gmpxx.h>
#include <math.h>

#define SIZE 50
#define XSIZE SIZE
#define YSIZE SIZE

#define FLOAT_PREC 256

using namespace std;

// typedef mpf_class base;
typedef mpq_class base;

int main(int argc, char *argv[])
{
  mpf_set_default_prec(FLOAT_PREC);
  base A[YSIZE][XSIZE],B[YSIZE];
  for(int i=0;i<YSIZE;i++){
    for(int j=0;j<XSIZE;j++){
      A[i][j] = 1;
      A[i][j] /= ((i+j+1)*(i+j+1));
    }
  }
  for(int i=0;i<YSIZE;i++){
    B[i] = 1;
  }
  for(int i=0;i<YSIZE;i++){
    for(int j=i+1;j<YSIZE;j++){
      base coeff = A[j][i]/A[i][i];
      for(int k=0;k<XSIZE;k++){
        A[j][k] -= coeff * A[i][k];
      }
      // cout<<A[j][i]<<endl;      // 0 になってほしい値 ここが0になっているものとして後退代入過程に移行しているが，実数だと誤差で0になっていないので注意．
      A[j][i] = 0;
      B[j] -= coeff * B[i];
    }
  }

  base x[YSIZE];
  for(int i=0;i<YSIZE;i++){
    base sum=0;
    for(int j=0;j<i;j++){
      sum += A[YSIZE-1-i][YSIZE-1-j]*x[YSIZE-1-j];
    }
    x[YSIZE-1-i] = (B[YSIZE-1-i]-sum)/A[YSIZE-1-i][YSIZE-1-i];
  }

  cout<<"type: "<<typeid(base).name()<<endl;
  cout<<"x_1: "<<x[0].get_d()<<endl;
  cout<<"prec: "<<x[0].get_prec()<<endl;
  return 0;
  
}


	
