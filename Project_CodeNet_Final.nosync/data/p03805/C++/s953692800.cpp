#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;
Graph G;

ll ans = 0;
ll n, m;
int dfs(int start, vector<int> houmon)
{
    houmon[start] = 1;
    ll tmp = 0;
    rep(i, n)
    {
        tmp += houmon[i];
    }
    if (tmp == n)
    {
        ans++;
        return 0;
    }
    else
    {
        for (auto g : G[start])
        {
            if (houmon[g] == 0)
            {
                dfs(g, houmon);
            }
        }
    }
    return 0;
}

int main()
{

    cin >> n >> m;
    G.resize(n);
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> houmon(n); //0で未訪問
    dfs(0, houmon);
    cout << ans << endl;
}