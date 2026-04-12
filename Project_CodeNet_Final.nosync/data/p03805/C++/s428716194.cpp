#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100
int n, m;
bool done(vector<bool> visited)
{
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    vi adj[9];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<bool> visited(9);
    queue<pair<int, vector<bool>>> q;
    visited[1] = 1;
    q.push(make_pair(1, visited));
    int ans = 0;
    while(!q.empty())
    {
        int node = q.front().first;
        vector<bool> visit = q.front().second;
        q.pop();
        if(done(visit))
        {
            ans++;
            continue;
        }
        for(auto u : adj[node])
        {
            vector<bool> visit2(visit);
            if(!visit2[u])
            {
                visit2[u] = 1;
                q.push(make_pair(u, visit2));
            }
        }
    }
    cout << ans << endl;
}