#include <bits/stdc++.h>
using namespace std;
     
#define int  long long
#define endl '\n'
const int MOD = 1e9 + 7;
const int INF = 1e18;

int dp[10005][120][2];
string k;
int d;

int get(int idx, int sum, int tight){
  if (idx == (int)k.size()) 
    return sum == 0;
  auto &ans = dp[idx][sum][tight];
  if (ans != -1)
    return ans;
  ans = 0;
  int lim = tight ? k[idx] - '0' : 9;
  for (int i = 0; i <= lim; i++){
	int new_tight = k[idx] - '0' == i ? tight : 0;
	ans += get(idx + 1, (sum + i) % d, new_tight);
	ans %= MOD;  
  } 	
  return dp[idx][sum][tight] = ans;
}

void solve(){
  memset(dp, -1, sizeof dp);
  cin >> k >> d;
  int ret =	(get(0, 0, 1) - 1 + MOD) % MOD;
  cout << ret << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();	
}
