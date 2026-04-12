#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
using PP = pair<int, int>;

int n;
int a[200000];
int b[200000];
int v[400000];
int q[400000];
void input() {
  cin >> n;
  vector<PP> p;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    p.push_back(PP(a[i], i));
    p.push_back(PP(b[i], i));
  }
  sort(p.begin(), p.end());
  map<int, int> mp;
  for (int i = 0; i < 2 * n; ++i) {
    v[i] = p[i].first;
    int k = p[i].second;
    if (mp.count(k)) {
      q[mp[k]] = i;
      q[i] = mp[k];
    } else {
      mp[k] = i;
    }
  }
}


bool mark[400000];
int main() {
  input();
  int bn = INF;
  int bx = 0;
  int wn = INF;
  int wx = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (q[i] > i) {
      mark[i] = true;
      bn = min(bn, i);
      bx = max(bx, i);
    } else {
      wn = min(wn, i);
      wx = max(wx, i);
    }
  }
  long mn = long(v[bx] - v[bn]) * (v[wx] - v[wn]);
  for (int i = 0; i < 2 * n; ++i) {
    int j = q[i];
    if (j < i) break;
    mark[i] = false;
    mark[j] = true;
    bn = i + 1;
    bx = max(bx, j);
    wn = min(wn, i);
    while (mark[wx]) {
      --wx;
    }
    long ans = long(v[bx] - v[bn]) * (v[wx] - v[wn]);
    mn = min(mn, ans);
  }
  cout << mn << endl;
  return 0;
}