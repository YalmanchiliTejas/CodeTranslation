
// Problem: C - Sum of product of pairs
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector <PII>
#define y2 y1919810
typedef pair <int, int> PII;
typedef vector <int> VI;
#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
#define RESET(x) memset((x), 0, sizeof(x))
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 200200;
const int mod  = 1e9 + 7;
int a[N]; int n; int sum[N];
void solve() {
  cin >> n;
  repn(i, n) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) sum[i] = (sum[i + 1] + a[i]) % mod;
  repn(i, n - 1) ans = (ans + sum[i + 1] * a[i] % mod) % mod;
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int T = 1;
  // cin >> T;
  while (T--) 
    solve();
  return 0;
}
