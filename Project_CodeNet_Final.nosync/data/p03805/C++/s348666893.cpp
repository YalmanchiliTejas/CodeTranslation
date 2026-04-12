#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< bool > seen;
int N;


int dfs( const vector< vector<int> > G, int v )
{
    bool all_v = true;
    seen[v] = true;
    for( int i = 0; i < N; ++i )
    {
        if( seen[i] == false )
        {
            all_v = false;
        }
    }

    if( all_v == true )
    {
        return 1;
    }

    int ret = 0;
    for( int i = 0; i < G[v].size(); ++i )
    {
        int nv = G[v][i];
        if( seen[nv] == true )
        {
            continue;
        }
        ret = ret + dfs( G, nv );
        seen[nv] = false;
    }
    return ret;
}

int main()
{
    int n,m;
    cin >> n >> m;
    N = n;
    vector< vector<int> > g(n);
    for( int i = 0; i < m; ++i )
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    seen.assign(n,false);
    int ans = dfs( g, 0 );
    cout << ans << endl;

    return 0;
}

