#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

vl n_layers(51), n_buns(51);

ll solve(int N, ll X){
  if (N==0){ return X;}
  else if (X<=1){ return 0;}
  else if (X<=n_layers[N-1]+1){ return solve(N-1, X-1);}
  else if (X==n_layers[N-1]+2){ return n_buns[N-1]+1;}
  else if (X<=n_layers[N]-1){
    return n_buns[N-1]+1+solve(N-1, X-n_layers[N-1]-2);
  }
  else {return n_buns[N];}
}

int main(){
  int N;ll X;cin >>N>>X;
  n_layers[0]=1;
  n_buns[0]=1;
  for (int i=0;i<50;i++){
    n_layers[i+1]=2*n_layers[i]+3;
    n_buns[i+1]=2*n_buns[i]+1;
  }

  cout << solve(N, X)<<endl;
  return 0;
}