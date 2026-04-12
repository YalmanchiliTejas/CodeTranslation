#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1000000007LL

#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1LL; i >= 0; i--)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rep1(i, n) for(int i = 1LL; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
/*
class Dinic {
public:
  vector<vector<pair<int, int>>> v;
  vector<int> e;

  vector<int> k;
  vector<int> j;

  void init(int n) {
    v = vector<vector<pair<int, int>>>(n);
    e = vector<int>();
    k = vector<int>(n);
    j = vector<int>(n);
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
            pq.push(make_pair(w + 1LL, i.first));
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
      if(k[v[p][j[p]].first] == k[p] + 1LL) {
        int r = dfs(s, t, v[p][j[p]].first, min(c - all, e[v[p][j[p]].second]));
        e[v[p][j[p]].second] -= r;
        e[v[p][j[p]].second ^ 1LL] += r;
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
    while(1LL) {
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
*/

signed main() {
  int a, b, c;
  cin >> a >> b >> c;
  if((a * 100 + b * 10 + c) % 4 == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
