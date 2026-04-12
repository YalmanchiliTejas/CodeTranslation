#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9+1;
const int MOD = 1e9+7;

int mod_pow(int x, int n){
  int res = 1;
  while ( n ) {
    if ( n & 1 ) (res *= x) %= MOD;
    (x *= x) %= MOD;
    n >>= 1;
  }
  return res;
}

int N;
vector<int> h;
vector<vector<int> > dp1, dp2;

void dfs(int l, int r) {
  int mi = INF;
  for ( int i = l; i < r; i++ ) mi = min(mi, h[i]);
  for ( int i = l; i < r; i++ ) h[i] -= mi;  
  int cnt_mi = 0;
  vector<int> p{l-1};  
  for ( int i = l; i < r; i++ ) {
    if ( h[i] == 0 ) {
      cnt_mi++;
      p.emplace_back(i);      
    }
  }
  p.emplace_back(r);  

  //cnt_mi = max(1LL, cnt_mi);  
  int mpow1 = mod_pow(2, cnt_mi);
  int mpow2 = mod_pow(2, mi);  
  dp1[l][r] = dp2[l][r] = 1;  
  for ( int i = 0; i < (int)p.size()-1; i++ ) {    
    if ( p[i]+1 >= p[i+1] ) continue;    
    dfs(p[i]+1, p[i+1]);
    (dp1[l][r] *= (dp1[p[i]+1][p[i+1]]+dp2[p[i]+1][p[i+1]])) %= MOD;    
    (dp2[l][r] *= dp2[p[i]+1][p[i+1]]) %= MOD;
  }
  (dp1[l][r] = mpow1*dp1[l][r]%MOD + (mpow2+MOD-2)*dp2[l][r]%MOD) %= MOD;
  (dp2[l][r] *= mpow2) %= MOD;

  for ( int i = l; i < r; i++ ) h[i] += mi;
}

signed main() {
  cin >> N;

  h = vector<int>(N);
  for ( int i = 0; i < N; i++ ) cin >> h[i];
  
  dp1 = dp2 = vector<vector<int> >(N+1, vector<int>(N+1, 0));

  dfs(0, N);

  cout << dp1[0][N] << endl;  
  
  return 0;
}
