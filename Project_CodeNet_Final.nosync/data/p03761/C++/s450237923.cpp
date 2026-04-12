#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> v(n);
  rep(i, 0, n) {
    cin >> v[i];
    sort(v[i].begin(), v[i].end());
  }

  string ans = v[0];
  int max_val = 0;
  rep(i, 1, n) {
    int nn = v[i].size();
    int c = 0, start = 0;
    string s = "";
    rep(j, 0, nn) {
      rep(k, start, ans.size()) {
        if (v[i][j] == ans[k]) {
          c++;
          s += ans[k];
          start = k + 1;
          break;
        }
      }
    }
    ans = s;
  }

  cout << ans << endl;
}
