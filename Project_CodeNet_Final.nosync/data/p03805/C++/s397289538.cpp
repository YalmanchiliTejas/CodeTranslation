#include <bits/stdc++.h>
using namespace std;
#define dbg(x) #x "=" << x << " "
#define fore(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> g[8];
bitset<8> vis;
int n, m;

ll dfs(int u, int cnt) {
    if (cnt == n) return 1;
    vis[u] = true;
    ll ans = 0;
    for (auto &v : g[u]) {
        if (!vis[v]) {
            ans += dfs(v, cnt+1);
            vis[v] = false;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int u, v;
    cin >> n >> m;
    fore(i,0,m) {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout << dfs(0, 1) << endl;
}
