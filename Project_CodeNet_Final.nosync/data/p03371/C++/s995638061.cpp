#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  int ans;
  int N,M;
  int H=0,HA=0,HB=0;
  cin>>A>>B>>C>>X>>Y;
  if(A+B>2*C)H=1;
  if(A>2*C)HA=1;
  if(B>2*C)HB=1;

  if(H==1){
    ans+=min(X,Y)*C*2;
    N = X+Y-min(X,Y)*2;
    if(min(X,Y)==Y&&HA==1){
      ans+=N*C*2;
    }
    else if(min(X,Y)==Y&&HA==0){
      ans+=N*A;
    }
    else if(min(X,Y)==X&&HB==1){
      ans+=N*C*2;
    }
    else{
      ans+=N*B;
    }
  }
  else{
    ans+=X*A+Y*B;
  }
  
  cout<<ans<<endl;
}