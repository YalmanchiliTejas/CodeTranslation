#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll x,y,z,a,b;
  cin >>x>>y>>z>>a>>b;
  if(2*z<=x+y){
    if(a>b && 2*z<x){
      cout << 2*z*a <<endl;
    }
    else if(b>a && 2*z<y){
      cout << 2*z*b <<endl;
    }
    else{
      if(a>=b){
        cout << 2*b*z+(a-b)*x <<endl;
      }
      else{
        cout << 2*a*z+(b-a)*y <<endl;
      }
    }
  }
  else{
    cout << a*x+b*y <<endl;
  }
}

