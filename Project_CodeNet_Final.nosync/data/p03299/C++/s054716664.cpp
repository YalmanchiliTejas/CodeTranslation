#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<P> child[101][101];
Int height[101][101];
Int h[101];
Int dp[101][101][2];

Int n;


Int mod_pow(Int x, Int a, Int m = MOD){
  if(a == 0)return 1;
  Int res = mod_pow(x, a / 2, m);
  res = res * res % m;
  if(a % 2)res *= x;
  return res % m;
}

Int inv(Int x, Int m = MOD){
  return mod_pow(x, m-2, m);
}

void dfs(int l, int r, int base = 0){
  height[l][r] = INF * 2;
  for(int i = l;i <= r;i++){
    height[l][r] = min(height[l][r], h[i]);
  }
  int nl = l;
  int nc = 0;
  for(int i = l;i <= r;i++)nc += height[l][r] == h[i];
  while(true){
    while(nl <= r && h[nl] <= height[l][r])nl++;
    if(nl > r)break;
    Int nr = nl;
    while(nr+1 <= r && h[nr+1] > height[l][r])nr++;
    child[l][r].push_back(P(nl, nr));
    dfs(nl, nr, height[l][r]);
    nl = nr+1;
  }
  
  height[l][r] -= base;
  dp[l][r][0] = mod_pow(2, height[l][r]);
  dp[l][r][1] = mod_pow(2, nc);
  Int pk = 1;
  for(auto c:child[l][r]){
    pk *= dp[c.first][c.second][0];pk %= MOD;
    dp[l][r][1] *= (dp[c.first][c.second][0]*2 + dp[c.first][c.second][1]) % MOD;dp[l][r][1] %= MOD;
  }
  dp[l][r][0] *= pk;dp[l][r][0] %= MOD;
  dp[l][r][1] -= 2*pk;dp[l][r][1] %= MOD;
  //  cout << l<< " " << r << " " <<  dp[l][r][0] << " " << dp[l][r][1] << endl;
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> h[i];
  }

  dfs(0, n-1);
  Int res = dp[0][n-1][0] + dp[0][n-1][1];res %= MOD;
  if(res < 0)res += MOD;
  cout << res << endl;
  return 0;
}