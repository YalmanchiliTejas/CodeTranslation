#include<iostream>
using namespace std;
int main(){
string st;
  cin>>st;
  int a=0;
  int b=0;
  for(int i=0; i<3; i++){
  if(st[i]=='A'){
  a++;
  }
    else{
    b++;}
  
  }
  if(a>0 && b>0){
  cout<<"Yes"<<endl;}
  else{
  cout<<"No";}
}