#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int n, a, b, c, d;
int dp[1001][1001];
int fact[1001][1001];
int m[1001][1001];

int add(int a, int b){
  return (a + b) % mod;
}
int mul(int a, int b){
  return ll(a) * b % mod;
}
int pow(int a, int n){
  int b = a;
  int s = 1;
  while(n){
    if(n & 1){
      s = mul(s, b);
    }
    n >>= 1;
    b = mul(b, b);
  }
  return s;
}
int inv(int a){
  return pow(a, mod - 2);
}

int main(){
  cin >> n >> a >> b >> c >> d;

  fact[0][1] = 1;
  for(int i = 1; i <= n; ++i){
    fact[i][1] = mul(fact[i - 1][1], i);
    for(int j = 2; j <= n; ++j){
      fact[i][j] = mul(fact[i][j - 1], fact[i][1]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int k = 1; k <= n; ++k){
      m[i][k] = inv(mul(fact[i][k], fact[k][1]));
    }
  }

  dp[a - 1][0] = 1;
  for(int i = a; i <= b; ++i){
    rep(j, n + 1){
      dp[i][j] = dp[i - 1][j];
      for(int k = c; k <= d && k * i <= j; ++k){
        dp[i][j] = add(mul(dp[i - 1][j - k * i], m[i][k]), dp[i][j]);
      }
    }
  }
  cout << mul(fact[n][1], dp[b][n]) << endl; 
  return 0;
}