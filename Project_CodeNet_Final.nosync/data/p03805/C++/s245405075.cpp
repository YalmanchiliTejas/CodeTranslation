#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << "\n"; }
template <class T, class... Args>
void debug_out(const T &x, const Args &... args) { cout << x << " "; debug_out(args...);}
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

int n, m;

ll dfs(int i, int bit, const vector<vector<int> > &G) {
  if (bit == (1<<n)-1) return 1;
  ll res = 0;
  for (auto u : G[i]) {
    if (bit & (1<<u)) continue;
    int nbit = bit|(1<<u);
    res += dfs(u, nbit, G);
  }
  return res;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  cin >> n >> m;
  vector<vector<int> > G(n);
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  ll ans = dfs(0,1,G);
  cout << ans << endl;
  return 0;
}