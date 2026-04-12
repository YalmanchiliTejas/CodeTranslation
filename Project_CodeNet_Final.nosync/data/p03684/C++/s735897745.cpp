#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

struct edge{
    ll cost;
    ll from;
    ll to;
    bool operator<(const edge &another) const {
        return cost > another.cost;
    };
};
priority_queue<edge> node;
int main(){
    int n;cin >> n;
    UnionFind UF(n);
    vector<LP> x,y;
    REP(i,n){
        ll xx,yy; cin >> xx >> yy;
        x.push_back(make_pair(xx,i));
        y.push_back(make_pair(yy,i));
    }
    sort(all(x));
    sort(all(y));
    REP(i,n-1){
        ll xcost = x[i+1].first - x[i].first;
        ll xfrom = x[i].second;
        ll xto   = x[i+1].second;
        ll ycost = y[i+1].first - y[i].first;
        ll yfrom = y[i].second;
        ll yto   = y[i+1].second;
        node.push(edge{xcost, xfrom, xto});
        node.push(edge{ycost, yfrom, yto});
    }
    ll ans=0;
    REP(i,n-1){
        edge e = node.top(); node.pop();
        while(UF.findSet(e.from, e.to)){
            e = node.top();
            node.pop();
        }
        ans += e.cost;
        UF.unionSet(e.from, e.to);
    }
    cout << ans << endl;

}