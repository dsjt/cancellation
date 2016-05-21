// 漸化式
// a_{n+2} = 34*a_{n+1}/11 - 3*a_{n}/11
// を解くプログラム
// 厳密解は
// a_n = 1/(11^n)
// 桁落ちの蓄積を観察する
#include <iostream>
#include <gmpxx.h>
#include <bitset>
#include <string>
#include <algorithm>
#include <typeinfo>
 
#define PREC 100

using namespace std;

// template <typename T>
// string to_bin_str(float n) {
//   float x=n;
//   unsigned int bit = (1 << (sizeof(int)*8-1));
//   string str="";
//   for(;bit!=0;bit>>=1){
//     if(*((int*)&x)&bit)str+='1';
//     else str+='0';
//     if(str.length()==1)str+=' ';
//     if(str.length()==10)str+=' ';
//   }
//   return str;
// }

// 引数の型はサイズが8バイトのものまでしか正常に実行できない
template <typename T>
string to_bin_str(T n) {
  T x=n;
  unsigned long int bit = ((unsigned long int)1 << (sizeof(T)*8-1));
  string str="";
  int counter=0;
  for(;bit!=0;bit>>=1){
    if(*((unsigned long int*)&x)&bit)str+='1';
    else str+='0';
  }
  return str;
}

int main(int argc, char *argv[])
{
  cout<<"単精度"<<endl;
  float a[50]={1.0,1.0/11.0,};
  for(int i=0;i<50-2;i++){
    a[i+2]=34.0*a[i+1]/11.0 - 3.0*a[i]/11.0;
  }
  for(int i=0;i<50;i++){
    printf("%20.17e\n",a[i]);
  }

  // printf("a[6]:%e\n",a[6]); 
  // printf("a[6]:%s\n",to_bin_str((float)a[6]).c_str()); 

  cout<<"倍精度"<<endl;
  double b[50]={1.0,1/11.0,};
  for(int i=0;i<50-2;i++){
    b[i+2]=34.0*b[i+1]/11.0 - 3.0*b[i]/11.0;
  }
  for(int i=0;i<50;i++){
    printf("%20.17e\n",b[i]);
  }
  
  cout<<"10進50桁"<<endl;
  // 10進50桁 〜 2進166桁
  mpf_set_default_prec(166);
  mpf_class c[50];
  c[0]=1;
  c[1]=1;
  c[1]/=11;
  
  for(int i=0;i<50-2;i++){
    c[i+2]= 34*c[i+1]/11 - 3*c[i]/11;
  }
  for(int i=0;i<50;i++){
    cout<<c[i].get_d()<<endl;
  }
  cout<<"prec:"<<c[49].get_prec()<<endl;

  cout<<"10進100桁"<<endl;
  // 10進50桁 〜 2進332桁
  mpf_set_default_prec(332);
  mpf_class d[50];
  d[0]=1;
  d[1]=1;
  d[1]/=11;
  
  for(int i=0;i<50-2;i++){
    d[i+2]= 34*d[i+1]/11 - 3*d[i]/11;
  }
  for(int i=0;i<50;i++){
    cout<<d[i].get_d()<<endl;
  }
  cout<<"prec:"<<d[49].get_prec()<<endl;
  return 0;
}
