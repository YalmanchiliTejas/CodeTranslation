#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull N;

struct UnionFind {
  vector<int> par;
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    for(int i=0;i<n;++i) par[i] = i;
  }

  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (sizes[x] < sizes[y]) swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];
    sizes[y] = 0;
  }

  void unite(pair<int,int> p) {
    unite(p.first,p.second);
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool same(pair<int,int> p) {
    return same(p.first,p.second);
  }

  int size(int x) {
    return sizes[find(x)];
  }
};

void fillmap(vector<pair<int,int>> xs, map<pair<int,int>,int> &m){
  for(auto it=xs.begin();it+1!=xs.end();++it) {
    int diff = abs(it->first-(it+1)->first);
    int t = it->second, n = (it+1)->second;
    auto key = t<n ? make_pair(t,n) : make_pair(n,t);
    m[key] = m.count(key) ? min(diff, m[key]) : diff;
  }
}

int main (int argc, char const *argv[])
{
  cin >> N;
  vector< pair<int,int> > xs,ys;
  for(int i=1;i<=N;++i) {
    int x,y;cin >> x >> y;
    xs.push_back(make_pair(x,i));
    ys.push_back(make_pair(y,i));
  }

  sort(xs.begin(),xs.end());
  sort(ys.begin(),ys.end());

  map< pair<int,int>,int > m;
  fillmap(xs,m);
  fillmap(ys,m);

  priority_queue< pair< int, pair<int,int> > > pq;

  for(auto &&kv:m) pq.push(make_pair(-kv.second,kv.first));

  auto uf = UnionFind(N+1);
  ll ans=0;
  while(pq.size()) {
    auto t = pq.top(); pq.pop();
    // cout << t.first << " : " << t.second.first << "," << t.second.second << endl;
    if(uf.same(t.second)) continue;
    uf.unite(t.second);
    ans += -t.first;
  }

  cout << ans << endl;
  return 0;
}
