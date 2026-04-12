#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
class UnionFind {
private:
    int sz;
    vector<int> par, nrank;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), nrank(sz, 0){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(nrank[x] < nrank[y]) swap(x,y);
        par[y] = x;
        if(nrank[x] == nrank[y]) nrank[x]++;
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};
struct edge{
    int from,to;
    ll cost;
    bool operator<(const edge&b) const{
        return cost < b.cost;
    }
};
vector<pair<int,ll>>g[4000];
ll dp[4000][4000];
void dfs(const int t, int s, int p){
    for(auto &x:g[s]){
        if(x.first==p)continue;
        int v = x.first;
        dp[t][v] = max(dp[t][s], x.second);
        dfs(t,v,s);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<edge>vec;
    while(m--){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--,b--;
        vec.push_back({a,b,c});
    }
    sort(vec.begin(),vec.end());
    UnionFind uf(n);
    ll sum = 0;
    for(auto &e:vec){
        if(!uf.same(e.from,e.to)){
            sum += e.cost;
            uf.unite(e.from,e.to);
            g[e.from].emplace_back(e.to,e.cost);
            g[e.to].emplace_back(e.from,e.cost);
        }
    }
    rep(i,n){
        dfs(i,i,-1);
    }
    int q;
    cin >> q;
    while(q--){
        int s,t;
        cin >> s >> t;
        s--,t--;
        cout << sum - dp[s][t] << "\n";
    }
}