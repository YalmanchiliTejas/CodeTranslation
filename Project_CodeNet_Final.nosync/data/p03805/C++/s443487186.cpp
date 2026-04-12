#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

vvint g;
int n;

int dfs(set<int> path, int v) {
    int res = 0;
    path.insert(v);
    if (path.size() == n) return 1;
    for (int n_v : g[v]) {
        if (path.find(n_v) != path.end()) continue;
        res += dfs(path,n_v);
    }
    return res;
}

int main() {
    int m; cin >> n >> m;
    g.resize(n);
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> path;
    cout << dfs(path,0) << endl;
}