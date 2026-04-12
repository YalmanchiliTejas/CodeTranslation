#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = INF;
  for (int i = 0; i <= max(x, y) * 2; i += 2) {
    ll total = 0;
    total += i * c;
    if (x - i / 2 >= 0) total += a * (x - i / 2);
    if (y - i / 2 >= 0) total += b * (y - i / 2);
    ans = min(ans, total);
  }

  cout << ans << endl;
  return 0;
}
