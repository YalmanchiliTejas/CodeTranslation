#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1000000007LL

#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)

class Dinic {
public:
  vector<vector<pair<int, int>>> v;
  vector<int> e;

  vector<int> k;
  vector<int> j;

  Dinic(int n) {
    v.resize(n);
    k.resize(n);
    j.resize(n);
  }
  void add_edge(int a, int b, int atob, int btoa = 0) {
    v[a].push_back(make_pair(b, e.size()));
    e.push_back(atob);
    v[b].push_back(make_pair(a, e.size()));
    e.push_back(btoa);
  }
  void dyk(int s) {
    for(auto& i : k) {
      i = inf;
    }
    queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
      int w = pq.front().first;
      int b = pq.front().second;
      pq.pop();
      if(k[b] > w) {
        k[b] = w;
        for(auto i : v[b]) {
          if(e[i.second] > 0) {
            pq.push(make_pair(w + 1, i.first));
          }
        }
      }
    }
  }
  int dfs(int s, int t, int p, int c) {
    if(p == t) {
      return c;
    }
    int all = 0;
    while(c > all && j[p] < v[p].size()) {
      if(k[v[p][j[p]].first] == k[p] + 1) {
        int r = dfs(s, t, v[p][j[p]].first, min(c - all, e[v[p][j[p]].second]));
        e[v[p][j[p]].second] -= r;
        e[v[p][j[p]].second ^ 1] += r;
        if(r < c - all) {
          j[p]++;
        }
        all += r;
      }
      else {
        j[p]++;
      }
    }
    return all;
  }
  int solve(int s, int t) {
    int all = 0;
    while(1) {
      dyk(s);
      for(auto& i : j) {
        i = 0;
      }
      int r = dfs(s, t, s, inf);
      if(r == 0) {
        return all;
      }
      all += r;
    }
  }
};

pair<int, int> d[334334];

signed main() {
  int n;
  cin >> n;
  int ma = 0;
  int mi = inf;
  rep(i, n) {
    cin >> d[i].first >> d[i].second;
    ma = max(ma, max(d[i].first, d[i].second));
    mi = min(mi, min(d[i].first, d[i].second));
  }
  int mami = inf;
  int mima = 0;
  rep(i, n) {
    mami = min(mami, max(d[i].first, d[i].second));
    mima = max(mima, min(d[i].first, d[i].second));
  }
  int ans = (ma - mami) * (mima - mi);
  int h = inf;
  int ww = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  rep(i, n) {
    pq.push(make_pair(min(d[i].first, d[i].second), i));
    ww = max(ww, min(d[i].first, d[i].second));
  }
  rep(i, n) {
    auto w = pq.top();
    pq.pop();
    h = min(h, ww - w.first);
    if(max(d[w.second].first, d[w.second].second) == w.first) {
      break;
    }
    ww = max(ww, max(d[w.second].first, d[w.second].second));
    pq.push(make_pair(max(d[w.second].first, d[w.second].second), w.second));
  }
  ans = min(ans, (ma - mi) * h);
  cout << ans << endl;
}
