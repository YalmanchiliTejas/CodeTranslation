#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> x, y;
vector< pair<int, int> > d;

using ll = long long;

ll solve1() {
  for(int i=0;i < n;i++)
    d.emplace_back(x[i], i),
    d.emplace_back(y[i], i);
  sort(begin(d), end(d));
  int rmin = d[0].first, bmax = d[n*2-1].first;
  int bmin = y[d[0].second], rmax = x[d[n*2-1].second];
  for(int i = 0; i < n ; i++) {
    if(i == d[0].second) continue;
    if(i == d[n*2-1].second) continue;
    rmax = max(rmax, x[i]);
    bmin = min(bmin, y[i]);
  }
  return ll (rmax - rmin) * (bmax - bmin);
}

ll solve2() {
  if(d[0].second == d[n*2-1].second) return (ll) 1e18;
  int rmin = d[0].first, rmax = d[n*2-1].first;
  ll res = 1e18;

  int bmax = y[d[0].second];
  for(int i = 1; i < 2*n-1 ; i++)
    if(d[i].second != d[0].second) bmax = max(bmax, x[d[i].second]);
  int ymin = y[d[0].second];

  set<int> st;
  for(int i = 1; i < 2*n-1 ; i++) {
    int j = d[i].second;
    if(j == d[0].second) continue;
    if(st.count(j)) continue;
    st.insert(j);
    int bmin = min(ymin, x[j]);
    
    res = min(res, ll (rmax - rmin) * (bmax - bmin));
    if(j == d[n*2-1].second) break;
    bmax = max(bmax, y[j]);
    ymin = min(ymin, y[j]);
  }
  return res;
}

int main() {
  cin >> n;
  x = vector<int>(n);
  y = vector<int>(n);
  for(int i=0;i < n;i++) {
    int s, t;
    cin >> s >> t;
    if(s > t) swap(s, t);
    x[i] = s; y[i] = t;
  }
  ll res = 1e18;
  res = min(res, solve1());
  res = min(res, solve2());
  cout << res << endl;
}
