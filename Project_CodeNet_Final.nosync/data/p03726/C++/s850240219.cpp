#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> adj[maxn];
ll d[maxn] , k[maxn];
void dfs(int v , int p = -1)
{
    d[v] = 1;
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        dfs(u , v);
        d[v] += d[u];
        if(d[u] & 1)
            k[v]++;
    }
}
int main()
{
    int n;
    cin >> n;
    if(n % 2)
    {
        cout << "First";
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        if(k[i] > 1 || (k[i] == 1 && (n - d[i]) % 2))
        {
            cout << "First";
            return 0;
        }
    }
    cout << "Second";
}
