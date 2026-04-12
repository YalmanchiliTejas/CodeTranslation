#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i>n;i--)
using namespace std;

int main(){
  int X,Y,Z;
  cin >>X>>Y>>Z;
  
  int ans = X/(Y+Z);
  if(X%(Y+Z)<Z) ans--; 
  
  cout <<ans<< endl;
}