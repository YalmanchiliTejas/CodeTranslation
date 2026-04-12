#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
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

const ll INF = 1LL<<60;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> res;
  res.emplace_back(a[0]);
  for (int i = 1; i < n; ++i) {
    int itr = lower_bound(rall(res), a[i]) - res.rbegin();
    if (itr == 0) res.emplace_back(a[i]);
    else res[res.size() - itr] = a[i];
    // for (auto x:res) debug(x);
    // debug(itr, a[i]);
    // debug();
  }
  cout << res.size() << endl;
  return 0;
}