#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
#include<vector>
#include<math.h>
using namespace std;

int main(){
  int pA,pB,pC,x,y;
  cin>>pA>>pB>>pC>>x>>y;
  long long int money=pA*x+pB*y;
  long long int tmp;
  //まず枚数を決めて値段を考えよう
  // Aをa枚、Bをb枚、Cをc枚とするとx<=a+c/2 y<=b+c/2
  int xy_min=min(x,y);
  int xy_max=max(x,y);
  //int aとint bを動かすとTLEでしょう。。。
  //cの枚数を動かしましょう!!
  for(int c=0;c<=2*xy_max;c++){
     int a=x-c/2; //マイナスにもなりうる
     int b=y-c/2; //マイナスにもなりうる
    if(a<0) a=0;
    if(b<0) b=0;
     tmp=pA*a+pB*b+pC*c;
     money=min(money,tmp);
  }
  cout<<money<<endl;
}