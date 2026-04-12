//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define MOD 1000000007

class Comb{
public:
  ll *fac,*finv,*inv;
  Comb(){
    fac = new ll[1000001];
    finv = new ll[1000001];
    inv = new ll[1000001];
    fac[0] = 1;
    for(int i=1;i<1000001;i++){
      fac[i] = i*fac[i-1];
      fac[i] %= MOD;
    }
    inv[1] = 1;
    for(int i=2;i<1000001;i++){
      inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
    }
    finv[0] = 1;
    for(int i=1;i<1000001;i++){
      finv[i] = inv[i]*finv[i-1];
      finv[i] %= MOD;
    }
  }
  ll calc(ll n,ll k){
    ll c = fac[n];
    c *= finv[k];c %= MOD;
    c *= finv[n-k];c %= MOD;
    return c;
  }
};

int main(){
  string N;
  cin >> N;
  int n,k;
  cin >> k;
  n = N.length();
  ll dp0[n+1][k+1],dp1[n+1][k+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<k+1;j++){
      dp0[i][j]=0;
      dp1[i][j]=0;
    }
  }

  dp1[0][0] = 1;
  for(int i=0;i<n;i++){
    dp0[i+1][0] = 1;
    dp1[i+1][0] = 0;
    for(int j=1;j<k+1;j++){
      if(N[i]=='0'){
        dp0[i+1][j] = dp0[i][j-1]*9+dp0[i][j];
        dp1[i+1][j] = dp1[i][j];
      }
      else{
        int d = N[i]-'0';
        dp0[i+1][j] = dp0[i][j-1]*9+dp0[i][j]+dp1[i][j]+dp1[i][j-1]*(d-1);
        dp1[i+1][j] = dp1[i][j-1];
      }
    }
  }
  cout << dp0[n][k]+dp1[n][k] << endl;
  return 0;
}
