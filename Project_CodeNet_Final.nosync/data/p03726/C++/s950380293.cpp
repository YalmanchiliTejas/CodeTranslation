#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...)name
#define _rep(i,n)repi(i,0,n)
#define repi(i,a,b)for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x)x
#define rep(...)MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c)c.begin(),c.end()
#define write(x)cout<<(x)<<'\n'
using namespace std; typedef long long ll; template<class T>using vv = vector<vector<T>>;
template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T, class U>bool chmax(T& a, U&& b) { return a < b ? a = b, 1 : 0; }
template<class T, class U>bool chmin(T& a, U&& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

int N;
vv<int> tree;
vector<bool> black, white;

void dfs_pre(int v, int p) {
    int bcnt = 0, wcnt = 0;
    for (int u : tree[v]) {
        if (u == p) continue;
        dfs_pre(u, v);
        bcnt += black[u];
        wcnt += white[u];
    }
    if (bcnt > 0) white[v] = true;
    if (wcnt == (int)tree[v].size() - (p != -1)) black[v] = true;
}

bool dfs(int v, int p, bool pb, bool pw) {
    int bcnt = pb, wcnt = pw;
    for (int u : tree[v]) {
        if (u == p) continue;
        bcnt += black[u];
        wcnt += white[u];
    }
    if (wcnt == (int)tree[v].size()) return true;
    for (int u : tree[v]) {
        if (u == p) continue;
        if (dfs(u, v, wcnt - white[u] == (int)tree[v].size() - 1, bcnt - black[u] > 0)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    tree.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    black.resize(N);
    white.resize(N);
    dfs_pre(0, -1);
    write(dfs(0, -1, false, false) ? "First" : "Second");
}