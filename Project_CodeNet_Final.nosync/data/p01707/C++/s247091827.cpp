#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int pow(int x, int n) {
  int ret = 1;
  while ( n > 0 ) {
    if ( n & 1 ) (ret *= x) %= MOD;
    (x *= x) %= MOD;
    n /= 2;    
  }
  return ret;
}

int inv(int x) {
  return pow(x, MOD-2);  
}

int dp[2010][2010];

signed main() {
  int N, D, X;
  while ( cin >> N >> D >> X, N ) {    
    fill_n(*dp, 2010*2010, 0);
    dp[0][0] = 1;
    for ( int i = 0; i < N; i++ ) {
      int sum = 0;      
      for ( int j = 0; j <= N; j++ ) {	
	if ( j >= X ) sum -= dp[i][j-X];	
	dp[i+1][j] += sum;
	dp[i+1][j] %= MOD;	
	sum += dp[i][j];
	sum %= MOD;
      }
    }
    /* for ( int i = 0; i <= N; i++ ) {
      for ( int j = 0; j <= N; j++ ) {
	cout << dp[i][j] << " ";
      }
      cout << endl;
      } */
    int ans = 0;
    for ( int i = 1; i <= min(D, N); i++ ) {
      int a = 1, b = 1;
      for ( int j = 0; j < i; j++ ) {
	a *= ((D-j)%MOD);	
	a %= MOD;
	b *= (i-j);	
	b %= MOD;	
      }
      int add = a*inv(b)%MOD;      
      add = add*dp[i][N]%MOD;
      ans += add;
      ans %= MOD;
    }

    if ( ans < 0 ) ans += MOD;    
    cout << ans << endl;
  }  
  return 0;
}

