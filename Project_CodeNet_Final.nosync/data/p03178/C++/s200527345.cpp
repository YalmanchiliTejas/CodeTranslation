#include <bits/stdc++.h>
 
#define FOR(i, a, b) for(int i = a; i < (int) b; i++)
#define F0R(i, a) FOR (i, 0, a)
#define ROF(i, a, b) for(int i = a; i >= (int) b; i--)
#define R0F(i, a) ROF(i, a, 0)
#define GO(i, a) for (auto i : a)
 
#define rsz resize
#define eb emplace_back
#define pb push_back
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f first
#define s second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef vector<pi64> vpi64;

string w;
int MOD;

const int N = 1e4 + 5;
const int D = 1e2 + 5;
const int G = 1e9 + 7;

i64 dp [N][D];

i64 solve (int p, int sum, bool tight) {
  if (p == -1) return sum == 0;
  if (tight && ~dp[p][sum]) return dp[p][sum];
  i64 tot = 0;
  for (int i = 0; i <= (tight ? 9 : w[p] - '0'); i++) {
    tot += solve (p - 1, (sum + i) % MOD, tight | (i < (w[p] - '0')));
    tot %= G;
  }
  return (tight ? dp[p][sum] = tot : tot);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> w >> MOD;
  reverse (all(w));
  memset (dp, -1, sizeof(dp));
  cout << (solve (sz(w) - 1, 0, 0) - 1 + G) % G << '\n';
  return 0;
}
