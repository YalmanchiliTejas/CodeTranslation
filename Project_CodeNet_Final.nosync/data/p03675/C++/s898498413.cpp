#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> num(n+1);
  num[0]=0;
  for(int i=1;i<n+1;i++){
    cin>>num[i];
  }int x=n;
  if(x%2==0){
    while(x>1){
      cout<<num[x]<<' ';
      x-=2;
    }x=1;
    while(x<n){
      cout<<num[x]<<' ';
      x+=2;
    }cout<<endl;
  }else{
    while(0<x){
      cout<<num[x]<<' ';
      x-=2;
    }x=2;
    while(x<n){
      cout<<num[x]<<' ';
      x+=2;
    }cout<<endl;
  }
}