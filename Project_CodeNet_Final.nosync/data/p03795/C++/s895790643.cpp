#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

  int N;
  cin >> N;    
  if((N<1)||(N>100)){
    return 0;
  }

  int tot=0;
  tot=N*800 - (N-N%15)/15*200;

  cout << tot;


}