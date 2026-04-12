#include <bits/stdc++.h>
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define fi first
#define se second
#define DEBUG(x) cerr << (#x) << ": " << (x) << '\n'
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
 
template<class T> bool uin(T &a, T b) {return (a < b ? false : (a = b, true));}
template<class T> bool uax(T &a, T b) {return (a > b ? false : (a = b, true));}
 
//~ ifstream f(".in");
//~ ofstream g(".out");
 
const int NMAX = 1e4 + 5;
const int MOD = 1e9 + 7;
 
int n, d;
char k[NMAX];

int main() {    
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL_DEFINE
  freopen(".in", "r", stdin);
#endif
 
  cin.getline(k + 1, NMAX);
  cin >> d; 
 
  n = strlen(k + 1);
  
  vector<vector<int>> dp(d, vector<int>(2));
  // dp[sum][0] = if no smaller digit so far and sum of digits % d == sum
  // dp[sum][1] = if already smaller and sum of digits % d == sum
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    vector<vector<int>> new_dp(d, vector<int>(2));
    for (int sum = 0; sum < d; ++sum) {
      for (int j : {0, 1}) {
        for (int dig = 0; dig < 10; ++dig) {
          if (j == 0 && dig > k[i] - '0') {
            break;
          }
          if (j == 0 && dig == k[i] - '0') {
            (new_dp[(sum + dig) % d][0] += dp[sum][j]) %= MOD;
          } else {
            (new_dp[(sum + dig) % d][1] += dp[sum][j]) %= MOD;
          }
        }
      }
    }
    dp = new_dp;
  }
  
  cout << ((dp[0][0] + dp[0][1]) % MOD + MOD - 1) % MOD << '\n';
 
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
