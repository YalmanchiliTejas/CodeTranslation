#include <bits/stdc++.h>
using namespace std;

struct data {
  string name;
  long long x;
};
bool operator<(const data &l, const data &r) {
  if(l.x != r.x) return l.x > r.x;
  return l.name < r.name;
}

long long n, m, k, l;
vector<data> v;
set<string> fav;
vector<long long> lst;

long long solve();
bool ch(long long top);

int main() {
  while(1) {
    cin >> n >> m >> k >> l;
    if(n + m + k + l == 0) break;
    v.resize(n);
    lst.clear();
    fav.clear();
    for(int i = 0; i < n; ++i) cin >> v[i].name >> v[i].x;
    for(int i = 0; i < m; ++i) {
      string s;
      cin >> s;
      fav.insert(s);
    }
    cout << solve() << endl;
  }
  return 0;
}

long long solve() {
  sort(v.begin(), v.end());
  for(int i = 0; i < n; ++i)
    if(fav.find(v[i].name) != fav.end()) lst.push_back(i);
  long long l = 0, r = min(k, m) + 1;
  while(r - l > 1) {
    long long now = (l + r) / 2;
    if(ch(now))
      l = now;
    else
      r = now;
  }
  return l;
}

bool ch(long long top) {
  long long remain = l, under = top;
  for(int i = 0; i < top; ++i) {
    long long nowid = lst[i];
    if(nowid <= k - under) {
      --under;
      continue;
    }
    remain -= v[k - under].x - v[nowid].x +
              (v[nowid].name > v[k - under].name);
  }
  return remain >= 0;
}
