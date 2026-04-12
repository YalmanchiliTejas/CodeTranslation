#include <bits/stdc++.h>
using namespace std;
inline void chmin (long long& a, long long b) {
  if (a > b) a = b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> dat(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> dat[2 * i].first >> dat[2 * i + 1].first;
    dat[2 * i].second = dat[2 * i + 1].second = i;
  }
  sort(dat.begin(), dat.end());
  int q = 2;
  int a, b;
  while (q--) {
    vector<int> ckd(n, false);
    a = dat[2 * n - 1].first;
    for (int i = 0; i < 2 * n; i++) {
      int ind = dat[i].second;
      if (ckd[ind]) {
        a -= dat[i].first;
        break;
      }
      ckd[ind] = true;
    }
    reverse(dat.begin(), dat.end());
    swap(a, b);
  }
  b = -b;
  long long ret = (long long)a * b;
  if (dat[0].second == dat[2 * n - 1].second) {
    cout << ret << '\n';
    return 0;
  }
  int l(1), r(1);
  vector<int> mlt(n);
  int cnt(0);
  long long c = (long long)dat[2 * n - 1].first - dat[0].first;
  while (r < 2 * n || cnt == n) {
    if (cnt < n) {
      int nxt = dat[r].second;
      if (!mlt[nxt]) cnt++;
      r++;
      mlt[nxt]++;
    } else {
      chmin(ret, c * (dat[r - 1].first - dat[l].first));
      int nxt = dat[l].second;
      l++;
      mlt[nxt]--;
      if (!mlt[nxt]) cnt--;
    }
  }
  cout << ret << '\n';
  return 0;
}