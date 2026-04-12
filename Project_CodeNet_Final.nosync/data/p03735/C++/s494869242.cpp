#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, long long>;
long long n;
vector<P> v;

long long solve();

int main() {
  cin >> n;
  v.resize(n);
  for (auto &p : v) {
    cin >> p.first >> p.second;
    if (p.first < p.second) swap(p.first, p.second);
  }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, now = 0, l = 0, r = 0;
  {  // search  default answer
    sort(v.begin(), v.end());
    res = v[n - 1].first - v[0].first;
    for (auto &p : v) swap(p.first, p.second);
    sort(v.begin(), v.end());
    res *= v[n - 1].first - v[0].first;
  }
  {
    int id = 0;
    for (int i = 0; i < n; ++i)
      if (v[id].second < v[i].second) id = i;
    if (!id) return res;
    swap(v[id].first, v[id].second);
    swap(v[1], v[id]);
    now = v[1].first - v[0].first;
    l = v[0].second;
    r = v[1].second;
    if (l > r) swap(l, r);
    for (int i = 2; i < n; ++i)
      if (v[i].first > r)
        r = v[i].first;
      else if (v[i].second < l)
        l = v[i].second;
    vector<P> tmp;
    for (int i = 2; i < n; ++i)
      if (v[i].first < l && r < v[i].second) tmp.push_back(v[i]);
    v = tmp;
  }
  for (auto p : v) {
    res = min(res, now * (r - p.first));
    r = max(r, p.second);
  }
  res = min(res, now * (r - l));
  return res;
}