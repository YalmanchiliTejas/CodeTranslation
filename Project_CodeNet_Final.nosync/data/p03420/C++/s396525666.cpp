#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define debug2(x, y)                       \
  cerr << "(" << #x << "," << #y << ") = " \
       << "(" << x << "," << y << ")\n"
#define all(x) x.begin(), x.end()
#define each(a, x) for (auto& a : (x))
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5 + 5, INF = 5LL << 57, MOD = 1e9 + 7;

int N, M;
string S;
vi va, vb;

int K;
void input() {
  cin >> N >> K;
  // int ans = (N - K) * (N - K + 1) / 2;
  // // cout << ans << endl;

  // int ans2 = 0;

  // rep(a, 1, N) {
  //   rep(b, K, a) {
  //     if (a % b >= K) {
  //       ans2++;
  //     }
  //   }
  // }
  // cout << ans + ans2 << endl;

  // ;
  // ;
}
int ans;
void solve() {
  ;
  if (K == 0) {
    cout << (N * N) << endl;
    return;
  }
  rep(b, K + 1, N) {
    int k = N % b;
    int p = N / b;
    ans += p * (max(0LL, b - K));
    ans += max(0LL, k - (K - 1));
  }
  cout << ans << endl;
  ;
}
signed main() {
  input();
  solve();
  return 0;
}