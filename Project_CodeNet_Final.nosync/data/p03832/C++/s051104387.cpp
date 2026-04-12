#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;
typedef vector<unordered_map<lli,lli>> graph;

const lli mod = 1000000007;

lli n,a,b,c,d;
mat dp;

lli factorial(lli n){
  static lli dp[100000];
  if(dp[n]) return dp[n];
  if(n == 0) return dp[n] = 1;
  return dp[n] = (n*factorial(n-1))%mod;
}

lli pow(lli x,lli r,lli mod = 1000000007){
  lli ret = 1;
  for(;r != 0;r >>= 1){
    if(r&1 != 0) ret *= x,ret %= mod;
    x *= x,x %= mod;
  }
  return ret;
}

lli inverse(lli x,lli mod = 1000000007){
  return pow(x,mod-2,mod);
}

int main(){
  cin >> n >> a >> b >> c >> d;
  dp = mat(n+1,vll(n+1));
  dp[0][0] = 1;
  for(lli i = 1;i <= n;i++){
    for(lli j = 0;j <= n;j++){
      dp[i][j] = dp[i-1][j];
      if(i >= a && i <= b){
        for(lli k = c;k <= d;k++){
          if(j-i*k < 0) break;
          lli x = dp[i-1][j-i*k];
          x *= factorial(j);x %= mod;
          x *= inverse(factorial(k)); x %= mod;
          x *= inverse(pow(factorial(i),k)); x %= mod;
          x *= inverse(factorial(j-i*k));x %= mod;
          dp[i][j] += x;
          dp[i][j] %= mod;
        }
      }
    }
  }
  cout << dp[n][n] << endl;
  return 0;

}
