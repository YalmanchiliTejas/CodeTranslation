#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll mod = (ll)1e9+7;
const int INF = 0x3f3f3f3f;

int a[100001];

int mpow(int b, int e)
{
    int ret=1;
    for(int i=0; i<e; i++)
    {
        ret=ret*b%mod;
    }
    return ret;
}

vector<int> g[9];
int ans=0;
ll n, m;

void dfs(int i, int s, vector<int> v)
{
    if(s==n)
    {
        ans++;
        return;
    }
    v[i]=1;
    for(int j=0; j<(int)g[i].size(); j++)
    {
        if(!v[g[i][j]])
        {
            dfs(g[i][j], s+1, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v(9);
    dfs(1, 1, v);
    cout << ans;
}