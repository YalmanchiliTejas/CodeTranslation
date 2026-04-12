#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
long long d[200009][2],n,m,S,T;
long long N[200009][2];
long long f[200009];
vector<long long> v[200009],l[200009];
void dij (long long V, long long h)
{
    for (long long i = 1; i <= n; i++)
    d[i][h]=1e18,f[i] = 0;
    d[V][h]=0;
    N[V][h]=1;
    priority_queue<pair<long long,long long > > q;
    q.push({0,V});
    while(q.size())
    {
        pair<long long,long long> F = q.top();
        q.pop();
        if(f[F.second]==1) continue;
        f[F.second]=1; long long u=F.second;
        for (long long i = 0; i < v[u].size(); i++)
        {
            long long L = d[u][h]+l[u][i];
            if(L < d[v[u][i]][h])
            {
                d[v[u][i]][h]=L;
                N[v[u][i]][h]=N[u][h];
                q.push({-L,v[u][i]});
            }
            else
            if(L == d[v[u][i]][h])
               {
                N[v[u][i]][h]=(N[v[u][i]][h]+ N[u][h]);
                if(N[v[u][i]][h] > mod) N[v[u][i]][h] -= mod;
               }
        }
    }
}
main()
{
    cin >> n >> m;
    cin >> S >> T;
    for (long long i = 0;  i < m ; i++)
    {
        long long a, b , c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        l[a].push_back(c);
        l[b].push_back(c);
    }
    dij(S,0);
    dij(T,1);
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        if(d[i][0]+d[i][1] == d[T][0] && d[i][0] == d[i][1])
            ans =(ans + N[i][0]*N[i][1]%mod*N[i][0]%mod*N[i][1]%mod)%mod;
    }
    //cout << ans << endl;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j =0; j<v[i].size(); j++)
        {
            long long x = i, y=v[i][j],L = l[i][j];
            if(d[x][0]+L+d[y][1]!=d[T][0] ) continue;
            if(abs(d[x][0] - d[y][1]) < L)
            {
                ans =(ans + N[x][0]*N[y][1]%mod*N[x][0]%mod*N[y][1]%mod)%mod;
            }
        }
    }
    ans = ((- ans)% mod+mod)%mod;
    ans = (ans + N[T][0]*N[T][0])%mod;
    cout << ans << endl;
 
}