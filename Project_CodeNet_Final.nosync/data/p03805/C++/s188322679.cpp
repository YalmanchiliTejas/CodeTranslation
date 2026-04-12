#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
int n,m;
bool vi[100];
vector<vector<int>> g;
int ans = 0;

bool check() {
    bool ret = true;
    REP(i,n) if (!vi[i]) ret = false;
    return ret;
}

void dfs(int x) {
    if (vi[x]) return;
    vi[x] = true;
    if (check()) ++ans;

    for (auto&& e: g[x]) {
        dfs(e);
    }
    vi[x] = false;
    return;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    g.resize(n);
    REP(i,m) {
        int a,b;
        cin >> a >> b; --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    REP(i,100) vi[i] = false;
    dfs(0);
    cout << ans << endl;
    return 0;
}