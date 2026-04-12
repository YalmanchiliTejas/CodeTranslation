#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
const int N = 1e5 + 10;
int n;
vi adj[N];

// dp[u][0] = matching maximo subarbol u
// dp[u][1] = matching maximo subarbol u, con u libre
int dp[N][2];
void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 0;
    bool add = false;
    for (auto v : adj[u]) if (v != p) {
        dfs(v,u);
        dp[u][1] += dp[v][0];
        add |= dp[v][1] == dp[v][0];
    }
    dp[u][0] = dp[u][1] + add;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    forn(_,n-1) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0,0);
    cout << (2*dp[0][0] == n ? "Second" : "First");
    return 0;
}
