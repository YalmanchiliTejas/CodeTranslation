#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  
  int sum=0;
  if(X<Y){
    if(A+B>=2*C){
      sum+=X*2*C;
      if(B>=2*C) sum+=(Y-X)*2*C;
      else sum+=(Y-X)*B;
    }
    else sum+=X*A+Y*B;
  }
  else{
    if(A+B>=2*C){
      sum+=Y*2*C;
      if(A>=2*C) sum+=(X-Y)*2*C;
      else sum+=(X-Y)*A;
    }
    else sum+=X*A+Y*B;
  }
  cout<<sum<<endl;
}