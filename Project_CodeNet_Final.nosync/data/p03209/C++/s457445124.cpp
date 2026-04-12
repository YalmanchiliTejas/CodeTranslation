#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num_layers(int n){
  if(n==0){return 1;}
  else{return 2*num_layers(n-1)+3;}
}

ll num_patties(int n){
  if(n==0){return 1;}
  else{return 2*num_patties(n-1)+1;}
}

ll solve(int n, ll x){
  if(n==0){return x<=0 ? 0:1;}
  if(x<=num_layers(n-1)+1){return solve(n-1, x-1);}
  if(x==num_layers(n-1)+2){return num_patties(n-1)+1;}
  if(x<=num_layers(n)-1){return num_patties(n-1)+1+solve(n-1,x-num_layers(n-1)-2);}
  else{return num_patties(n);}
}

int main(){
  int N; ll X;cin>>N>>X;
  ll ans=solve(N, X);
  cout << ans << endl;
  return 0; 
}