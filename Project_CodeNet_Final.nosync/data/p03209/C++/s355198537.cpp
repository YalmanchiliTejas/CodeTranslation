#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 5000
#define MOD 1000000007

ll solve(ll level,ll X){
  if(X==0){
    return 0;
  }
  if(X==((1ull<<(level+2))-3)){
    return (1ull<<(level+1))-1;
  }
  ll x=(1ull<<(level+1))-1;
  if(X<x){
    return solve(level-1,X-1);
  }else if(X>x){
    return (1ull<<level)+solve(level-1,X-x);
  }else{
    return 1ull<<(level);
  }
}

int main(){
  ll N,X;
  cin>>N>>X;
  cout<<solve(N,X)<<endl;
}
