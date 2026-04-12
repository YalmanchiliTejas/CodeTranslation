#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(begin(v), end(v));
  map<int, int> mp;
  rep(i, n) mp[v[i]] = i;
  vector<vector<bool>> used(n, vector<bool>(n, false));
  int ans = 0;
  rep(i, n) rep(j, n) {
    if (i >= j) continue;
    int d = v[j] - v[i];
    int nxt = v[j] + d;
    int c = 2;
    while (mp.find(nxt) != mp.end() && !used[mp[nxt - d]][mp[nxt]]) {
      used[mp[nxt - d]][mp[nxt]] = true;
      nxt = v[mp[nxt]] + d, c++;
    }
    ans = max(ans, c);
  }
  cout << ans << endl;
}

