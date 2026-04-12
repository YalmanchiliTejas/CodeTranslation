#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

vector<vector<int>> g;

int dfs(vector<bool> v,const int par, const int cur) {
    int ret = 0;
    v[cur] = true;
    bool all = true;
    REP(i,v.size()) if (!v[i]) all = false;
    if (all) return 1;

    for (auto x:g[cur]) {
        if (x == par) continue;
        if (v[x]) continue;
        ret += dfs(v,cur,x);
    }
    
    return ret;
}

int main(void)
{
    IOS
    int n, m;
    cin >> n >> m;
    g.resize(n);
    REP(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    vector<bool> v(n);
    ans = dfs(v,-1,0);

    cout << ans << '\n';

    return 0;
}