#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

int dp[101][4][2];
string S;
int K;

int dfs(int n, int k, bool f) {
  if ( dp[n][k][f] >= 0 ) return dp[n][k][f];

  if ( n == S.size() ) {
    if ( k == K ) return 1;
    else return 0;
  }

  int ret = 0;
  if ( k < K ) {
    if ( !f ) {
      for ( int i = 1; i <= (S[n]-'0'); i++ ) {
	if ( i == (S[n]-'0') ) ret += dfs(n+1, k+1, f);
	else ret += dfs(n+1, k+1, true);      
      }
    } else {
      for ( int i = 1; i <= 9; i++ ) {
	ret += dfs(n+1, k+1, true);	
      }
    }
  }
  if ( (S[n]-'0') == 0 ) ret += dfs(n+1, k, f);
  else ret += dfs(n+1, k, true);

  return dp[n][k][f] = ret;  
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> S >> K;
  fill_n(**dp, 101*4*2, -1);

  cout << dfs(0, 0, 0) << endl;
  
  return 0;
}
