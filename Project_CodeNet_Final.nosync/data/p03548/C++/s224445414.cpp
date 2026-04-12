#include<iostream>
using namespace std;
int main(void){
  int x,y,z;
  cin>>x>>y>>z;
  x-=z;
  int a=x/(y+z);
  cout<<a<<endl;
  return 0;
}