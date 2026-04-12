#include <bits/stdc++.h>
using namespace std;

long long n, s, t;
vector<vector<long long>> dist;

void solve();
long long query(long long x, long long y) {
  cout << "? " << x << " " << y << endl;
  long long i;
  cin >> i;
  return i;
}

int main() {
  cin >> n >> s >> t;
  dist.assign(n + 1, vector<long long>(n + 1, 0));
  solve();
  return 0;
}

void solve() {
  dist[s][t] = dist[t][s] = query(s, t);
  vector<long long> v, res;
  res.push_back(s);
  for(int i = 1; i <= n; ++i)
    if(i != s && i != t) {
      long long in1 = query(s, i), in2 = query(i, t);
      dist[s][i] = in1;
      dist[i][t] = in2;
      if(in1 + in2 == dist[s][t]) v.push_back(i);
    }
  auto f = [](long long &l, long long &r) {
    return dist[s][l] < dist[s][r];
  };
  int vsize = v.size();
  sort(v.begin(), v.end(), f);
  for(int i = 0; i < vsize; ++i) {
    long long now = query(res.back(), v[i]);
    dist[res.back()][v[i]] = now;
    if(dist[s][res.back()] + now == dist[s][v[i]])
      res.push_back(v[i]);
  }
  res.push_back(t);
  cout << "!";
  for(int i = 0; i < res.size(); ++i) cout << " " << res[i];
  cout << endl;
}

