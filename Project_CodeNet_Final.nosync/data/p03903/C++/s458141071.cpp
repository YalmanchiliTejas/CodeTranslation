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
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};
struct edge{
    int to;
    ll cost;
};
vector<edge> g[5000];
int dp[5000][5000];
void dfs(const int s, int par,int t){
    for(auto &x : g[t]){
        if(x.to == par)continue;
        dp[s][x.to] = max(dp[s][t], (int)x.cost);
        dfs(s,t,x.to);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<pair<ll,pii>>e;
    while(m--){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--,b--;
        e.push_back({c,{a,b}});
    }
    sort(e.begin(),e.end());
    UnionFind uf(n);
    ll sum = 0;
    for(auto &x: e){
        if(!uf.same(x.second.first,x.second.second)){
            uf.unite(x.second.first,x.second.second);
            sum += x.first;
            int a = x.second.first;
            int b = x.second.second;
            ll c = x.first;
            g[a].push_back((edge){b,c});
            g[b].push_back((edge){a,c});
        }
    }
    show(sum);
    rep(i,n)dfs(i,-1,i);
    int q;
    cin >> q;
    while(q--){
        int s,t;
        cin >> s >> t;
        s--,t--;
        cout << sum - dp[s][t] << "\n";
    }
}