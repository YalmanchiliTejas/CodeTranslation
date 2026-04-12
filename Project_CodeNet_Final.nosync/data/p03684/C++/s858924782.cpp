#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
const int INF = 1e12;

struct UF{
   vector<int> par;
   vector<int> sz;
   UF(){}
   UF(int n){
       par.resize(n);
       sz.resize(n, 1);
       rep(i, 0, n) par[i] = i;
   }
   int find(int x){
       if(x == par[x]) return x;
       return par[x] = find(par[x]);
   }
   void unite(int x, int y){
       x = find(x); y = find(y);
       if(x == y) return;
       if(sz[x] < sz[y]) swap(x, y);
       sz[x] += sz[y];
       par[y] = x;
   }
   bool same(int x, int y){
       return find(x) == find(y);
   }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<PP> edge; 
    vector<int> x(n), y(n);
    vector<P> dx, dy; 
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        dx.push_back(P(x[i], i));
        dy.push_back(P(y[i], i));
    }
    sort(all(dx));
    sort(all(dy));
    rep(i, 0, n - 1){
        int now = dx[i].second;
        int next = dx[i + 1].second;
        int cost = x[next] - x[now];
        edge.push_back(PP(cost, P(now, next)));
    }
    rep(i, 0, n - 1){
        int now = dy[i].second;
        int next = dy[i + 1].second;
        int cost = y[next] - y[now];
        edge.push_back(PP(cost, P(now, next)));
    }
    sort(all(edge));
    int ans = 0;
    UF uf(n);
    rep(i, 0, edge.size()){
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        if(!uf.same(u, v)){
            ans += edge[i].first;
            uf.unite(u, v);
        }
    }
    cout << ans << endl;
}