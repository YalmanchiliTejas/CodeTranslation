#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
ll fact [1001];
ll dp[1005][1005];
ll N,A,B,C,D;

ll p(ll x, ll a) {
  ll res = 1;
  while(a > 0) {
    if(a & 1) res = x * res % mod;
    
    x = x * x % mod;

    a >>= 1;
    
  }
  return res % mod;
}

ll r_fact(ll x) {
  return p(x,mod-2);
}

ll get_P(ll n, int r) {
  return fact[n] * r_fact(fact[n-r]) % mod;
}

int main() {
  cin >> N >> A >> B >> C >> D;

  fact[0] = 1;
  for(int i = 1; i <= N; i++) {
    fact[i] = (fact[i-1] * i) % mod;
  }

  dp[A-1][0] = 1;
  for(int i = A; i <= B; i++) {
    for(int j = 0; j <= N; j++) dp[i][j] = dp[i-1][j];
    for(int k = C; k <= D; k++) {
      for(int j = i * k; j <= N; j++) {
	dp[i][j] = (dp[i][j] + (dp[i-1][j-i*k] * get_P(j,i*k) % mod) * r_fact(p(fact[i],k) * fact[k] % mod) % mod) % mod;
      }
    }
  }
  cout << dp[B][N] << endl;
}
  

  

  
