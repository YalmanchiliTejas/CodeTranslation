#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const long double PI = acos(-1.0L);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> score(n);
    rep(i, n)
      cin >> score[i];
    sort(score.begin(), score.end());
    int ans = 0;
    for (int i = 1; i+1 < n; i++)
      ans += score[i];
    ans /= n-2;
    cout << ans << '\n';
  }
  return 0;
}
