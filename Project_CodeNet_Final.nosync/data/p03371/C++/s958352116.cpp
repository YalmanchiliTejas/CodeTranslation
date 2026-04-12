#include<bits/stdc++.h>
#define rep(i,x) for(int i = 0; i<x; i++)

typedef long long ll;
using namespace std;

int main(){
  ll A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;

  ll ans = 0;
  ll XY_min = min(X,Y);


  if(A+B >= 2*C){
    X -= XY_min;
    Y -= XY_min;
    ans += 2 * C * XY_min;
    //cout <<ans;
  }

  if(A >= 2*C){
    ans += 2 * C * X;
    X = 0;
  }else{
    ans += A * X;
    X =0;
  }
  if(B >= 2*C){
    ans += 2 * C * Y;
    Y= 0;
  }else{
    ans += B * Y;
    Y = 0;
  }

  cout<<ans;
}
