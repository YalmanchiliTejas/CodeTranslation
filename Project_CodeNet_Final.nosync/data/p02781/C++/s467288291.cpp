#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); } 
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
#define forxr(i,n) for(int i = (n)-1; i >= 0; --i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll,ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second
#define all(c) c.begin(),c.end()

const int N = 105;
string s;
ll dp[N][4][2]; //dp [i][k][b] = # ways to assign numbers i..n such that k non-zero numbers are left, and b=true if we are equal to n so far

ll solve(int i, int k, bool b) {
  if (k < 0) return 0;
  if (i == s.size()) return k==0;
  if (dp[i][k][b] == -1) {
    dp[i][k][b] = 0;
    int dig = s[i] - '0';
    if (b) {
      //maintain equality
      dp[i][k][b] += solve(i+1, k - (dig > 0), 1);
      //go less than dig
      for (int d = 0; d < dig; ++d) {
        dp[i][k][b] += solve(i+1, k - (d > 0), 0);
      }
    } else {
      dp[i][k][b] += solve(i+1, k, 0);
      for (int d = 1; d <= 9; ++d) {
        dp[i][k][b] += solve(i+1, k-1, 0);
      }
    }
  }
  return dp[i][k][b];
}

int main() {
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(12);
  // Emily <3
  memset(dp, -1, sizeof dp);
  cin >> s;
  int k; cin >> k;
  cout << (solve(0, k, 1)) << nl;

  return 0;
}

