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

  int n; cin >> n;
  vector<ll> vec(n);
  rep(i, n) cin >> vec[i];

  ll ans = 0;
  vector<bool> used(n);
  vector<int> keep;
  for(int k=1; ; k++) {
    //debug(k);
    int a = n-1-k;
    int b = k;
    if (b >= a || b >= n) break;
    ll now = 0;
    //debug(a); debugln(b);
    now += vec[a];
    now += vec[b];
    used[a] = true;
    used[b] = true;
    keep.push_back(a);
    keep.push_back(b);
    chmax(ans, now);
    while(true) {
      a -= k;
      b += k;
      if (a==b || a <= k || b >= n || used[a] || used[b]) {
        break;
      }
      //debug(a); debugln(b);
      used[a] = true;
      used[b] = true;
      keep.push_back(a);
      keep.push_back(b);
      now += vec[a] + vec[b];
      chmax(ans, now);
    }
    for(auto e: keep) {
      //debugln(e);
      used[e] = false;
    }
    keep.clear();
  }
  cout << ans << endl;
}