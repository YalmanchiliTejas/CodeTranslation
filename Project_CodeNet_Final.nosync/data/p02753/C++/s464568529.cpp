#include<iostream>
#include<stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
     
int main(){
  //整数の時はint
  //int a,b,c;
  //文字の時はstring
  string a;
     
     
  cin>>a;
  if(a=="AAA" || a=="BBB")
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  return 0;
}
