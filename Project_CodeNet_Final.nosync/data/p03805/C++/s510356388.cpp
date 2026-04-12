#include<bits/stdc++.h>

#define LL long long
#define Dl double
#define Pb push_back
#define Po pop_back
#define Mp make_pair
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

typedef vector<LL> Vl;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef vector<Pll> Vpl;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
#define X first
#define Y second
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

VVl g;
bool vis[12];
LL n, m;

LL dfs(LL u)
{
    LL x = 0;
    for(LL i = 1; i <= n; i++)
        if(vis[i])
            x++;

    if(x == n)
        return 1;

    LL ans = 0;
    for(auto i: g[u]){
        if(!vis[i]){
            vis[i] = true;
            ans += dfs(i);
            vis[i] = false;
        }
    }

    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> n >> m;

    g.resize(n + 5);
    for(LL i = 0; i < m; i++){
        LL a, b;
        cin >> a >> b;

        g[a].Pb(b);
        g[b].Pb(a);
    }

    vis[1] = true;
    cout << dfs(1) << '\n';
    return 0;
}

