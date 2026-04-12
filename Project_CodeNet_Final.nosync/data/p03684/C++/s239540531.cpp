#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

class UnionFind {
  std::vector<int> p;
public:
  UnionFind(int n) : p(n, -1) {}
  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) std::swap(x, y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;
    return true;
  }
};
int main(void)
{
  LL n;
  cin >> n;
  vector<pair<LL,LL>> x(n),y(n);
  UnionFind uf(n);
  REP(i,n) cin >> x[i].first >> y[i].first;
  REP(i,n) x[i].second=y[i].second=i;
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  vector<tuple<LL,LL,LL>> cost;
  REP(i,n-1) {
    cost.emplace_back(x[i+1].first-x[i].first,x[i].second,x[i+1].second);
    cost.emplace_back(y[i+1].first-y[i].first,y[i].second,y[i+1].second);
  }
  sort(cost.begin(),cost.end());
  LL answer=0ll;
  for(auto t:cost) {
    LL c,l,r;
    tie(c,l,r)=t;
    if(uf.unite(l,r)) answer+=c;
  }
  cout << answer << endl;
  return 0;
}
