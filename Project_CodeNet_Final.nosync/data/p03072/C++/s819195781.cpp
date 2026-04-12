#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, 0, N) cin >> H[i];

  int ans = 1;
  rep(i, 1, N) {
    bool ok = true;
    rep(j, 0, i) {
      if (H[i] < H[j]) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  }

  cout << ans << endl;

  return 0;
}
