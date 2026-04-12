#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 2100000000
#define MOD 1000000007

bool dbgflag = false; //debug

ll dpfunc(int i, int j, vector<vector<ll>>&dp, string s) {
  if (dbgflag) cout << "dp " << i << " " << j << endl; 
  int n = s.size();
  if (dp[i][j] != -1) return dp[i][j];
  if (j == 0) { if (dbgflag) cout << "case1" << endl;
    dp[i][j] = 1;
    return dp[i][j];
  }
  if (n-i < j) { if (dbgflag) cout << "case2" << endl;
    dp[i][j] = 0;
    return dp[i][j];
  }
  if (i == n-1) { if (dbgflag) cout << "case3" << endl;
    dp[i][j] = (ll)(s[i]-'0');
    return dp[i][j];
  }
  //0から始まるとき
  if (s[i] == '0') { if (dbgflag) cout << "case4" << endl;
    dp[i][j] = dpfunc(i+1, j, dp, s);
    return dp[i][j];
  }
  //0でないとき
  if (s[i] != '0') { if (dbgflag) cout << "case5" << endl;
    //上の桁が同じ
    dp[i][j] = dpfunc(i+1, j-1, dp, s); 
    //なんでもよくなったけど0でない
    ll ansn0 = (s[i] - '1');
    for (int p = 0; p < j-1; p++) ansn0 *= (ll) (n-i-1-p);
    for (int p = 0; p < j-1; p++) ansn0 /= (p+1);
    for (int p = 0; p < j-1; p++) ansn0 *= 9;
    //なんでもいい
    ll ansy0 = 1;
    for (int p = 0; p < j; p++) ansy0 *= (ll) (n-i-1-p);
    for (int p = 0; p < j; p++) ansy0 /= (p+1);
    for (int p = 0; p < j; p++) ansy0 *= 9;
    
    if (dbgflag) cout << dp[i][j] << " " << ansn0 << " " << ansy0 << endl;
    dp[i][j] += ansn0 + ansy0;
    return dp[i][j];
  }
  return dp[i][j];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  int n = s.size();
  int k;
  cin >> k;

  vector<vector<ll>> dp(n, vector<ll>(k+1, -1)); //dp[i][j]: 左からi桁目以降の数字より小さく、j個の0以外の数
  //最上位桁が0
  /*ll ans = 1;
  for (int i = 0; i < k; i++) ans *= (ll) (n-1-k);
  for (int i = 0; i < k; i++) ans /= (i+1);
  for (int i = 0; i < k; i++) ans *= 9;
  */

  cout << dpfunc(0, k, dp, s) << endl;
  
}
