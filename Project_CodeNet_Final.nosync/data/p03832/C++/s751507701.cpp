#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;

//factorial&inverse factorial
ll fc[200010];
ll ifc[200010];

ll add(ll x, ll y){return (x+y)%MOD;}
ll mlt(ll x, ll y){return (x*y)%MOD;}

ll power(int x, int n){
  ll ans=1;
  while(n>0){
    if(n%2!=0){ans=mlt(ans, x);}
    x=mlt(x,x);
    n/=2;
  }
  return ans;
}

ll inv(ll x){
  return power(x, MOD-2);
}

void fct(){
  fc[0]=1;
  for (int i=0;i<200009;++i){
    fc[i+1]=mlt(fc[i], i+1);
  }
}

void ifct(){
  ifc[200009]=inv(fc[200009]);
  for (int i=200009;i>=1;--i){
    ifc[i-1]=mlt(ifc[i], i);
  }
}

ll comb(int n, int k){
  if(n<0||k<0|| k>n)return 0;
  return mlt(fc[n], mlt(ifc[k], ifc[n-k]));
}

int main(){
  int N, A, B, C, D;cin>>N>>A>>B>>C>>D;

  ll dp[1010][1010]={};
  dp[N][B+1]=1;
  fct();ifct();

  for (int j=B;j>=A;--j){
    for (int i=0;i<=N;++i){
      dp[i][j]=dp[i][j+1];
      ll factor=1;
      for (int k=0;k++<C-1;){
        factor=mlt(factor, comb(i+k*j, j));
      }

      for (int k=C;k<=D;++k){
        if(i+k*j>N) break;
        factor=mlt(factor, comb(i+k*j, j));
        dp[i][j]=add(dp[i][j], mlt(dp[i+k*j][j+1], mlt(factor, ifc[k])));
      }
    }
  }

  cout << dp[0][A]<< endl;
  return 0;
}
