#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
ll x[100006];
ll y[100006];
ll pre[100006];
ll cfind(ll a) {
  if (pre[a] != a) pre[a] = cfind(pre[a]);
  return pre[a];
}

void cunion(ll a, ll b) {
  ll r1 = cfind(a);
  ll r2 = cfind(b);
  pre[r1] = r2;
}

ll dist(ll x1, ll y1, ll x2, ll y2) {
  return min(abs(x1 - x2), abs(y1 - y2));
}
ll pdist(ll p1, ll p2) {
  return dist(x[p1], y[p1], x[p2], y[p2]);
}

ll calc() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
  }
  vector<pair<int, int>> edges;
  edges.reserve(2 * N);
  for (int i = 0; i < N; ++i) pre[i] = i;
  vector<int> ind(N);
  iota(ind.begin(), ind.end(), 0);
  sort(ind.begin(), ind.end(),
       [](const int i1, const int i2) { return x[i1] < x[i2]; });

  for (int i = 0; i < N - 1; ++i) {
    ll a = ind[i];
    ll b = ind[i + 1];
    if (a > b) swap(a, b);
    edges.push_back({a, b});
  }
  sort(ind.begin(), ind.end(),
       [](const int i1, const int i2) { return y[i1] < y[i2]; });
  for (int i = 0; i < N - 1; ++i) {
    ll a = ind[i];
    ll b = ind[i + 1];
    if (a > b) swap(a, b);
    edges.push_back({a, b});
  }
  sort(edges.begin(), edges.end());
  int len = unique(edges.begin(), edges.end()) - edges.begin();
  edges.resize(len);

  sort(edges.begin(), edges.end(), [](const pair<int,int> &p1, const pair<int,int> &p2){
    ll dist1 = pdist(p1.first, p1.second);
    ll dist2 = pdist(p2.first, p2.second);
    return dist1 < dist2;
  });

  ll ret = 0;
  // cout << "edges' size" << edges.size() << endl;
  int ct = 0;
  for(auto const &e: edges) {
    int p1 = e.first;
    int p2 = e.second;

    if (cfind(p1) == cfind(p2)) continue;
    // cout << "p1, p2, dist: " << p1 << ' ' << p2 << ' ' << pdist(p1, p2) << endl;
    cunion(p1, p2);
    ct++;
    ret += pdist(p1, p2);
    if (ct == N - 1) break;
  }
  assert(ct == N - 1);
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout << calc() << endl;

}