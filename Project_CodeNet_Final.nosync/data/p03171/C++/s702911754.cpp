#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

#define rep(i, a, b) for(auto i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back

struct edge{int to;};
using graph = vector<vector<edge>>;

const int MAXN = 3000;
const ll sentinel = 1e15;
ll dp[MAXN + 5][MAXN + 5][2]; // len, start, player

auto minn(auto& a, auto b){a = (a == sentinel) ? b : min(a, b);}
auto maxx(auto& a, auto b){a = (a == sentinel) ? b : max(a, b);}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vi a(n);
  trav(i, a) cin >> i;

  rep(len, 0, n + 1) rep(i, 0, n) rep(k, 0, 2)
    dp[len][i][k] = sentinel;
  rep(i, 0, n) rep(k, 0, 2)
    dp[0][i][k] = 0;
    
  rep(len, 1, n + 1) {
    rep(i, 0, n - len + 1) {
      int j = i + len - 1;
      maxx(dp[len][i][0], a[i] + dp[len - 1][i + 1][1]);
      maxx(dp[len][i][0], a[j] + dp[len - 1][i][1]);
      minn(dp[len][i][1], dp[len - 1][i + 1][0] - a[i]);
      minn(dp[len][i][1], dp[len - 1][i][0] - a[j]);
    }
  }  
  cout << dp[n][0][0] << '\n';
}
