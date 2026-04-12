#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//constexpr ll mod = 998244353;
constexpr ll mod = 1e9+7;
const double PI = acos(-1.0);
mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; cin >> n >> k;
  if (k == 0) {
    cout << n*n << endl;
    return 0;
  }
  ll ans = 0;
  for(auto i=k+1; i<=n; i++) {
    auto r = n/i;
    ans += r*(i-k);
    r = n-(n/i)*i;
    ans += max(r-k+1, 0LL);
  }
  cout << ans << endl;
}