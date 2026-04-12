#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 100005
#define MOD 1000000007

vector < pair < int , int > > a[N];
int vis[N];
int n;

void init(int s,int t, vector < int > &dp, vector < int > &dist)
{
    priority_queue < pair < int , int > , vector < pair < int ,int > > , greater < pair < int , int >> > pq;

    pq.push({0, s});
    for(int i=1;i<=n;i++)  
    {
        vis[i] = 0;
    }
    dist[s] = 0;

    while(!pq.empty())
    {
        pair < int , int > cur = pq.top();
        pq.pop();
        int u = cur.second;
        if( vis[u] )
            continue;
        dist[u] = cur.first;
        vis[u] = 1;
        for(int i=0; i<a[u].size();i++)
        {
            int v = a[u][i].first;
            int w = a[u][i].second;

            if( dist[v] > (dist[u] + w))
            {
                pq.push({ dist[u] + w, v});
            }
        }
    }

    vector < pair < int , int > > temp;
    for(int i=1;i<=n;i++)
    {
        temp.push_back({dist[i], i});
    }
    sort(temp.begin(), temp.end());
    dp[s] = 1;
    for(int i=1;i<temp.size();i++)
    {
        int u = temp[i].second;
        for(int j=0;j<a[u].size();j++)
        {
            if( (dist[a[u][j].first] + a[u][j].second) == dist[u] )
            {
                dp[u]+=dp[a[u][j].first];
            }
        }
        dp[u]%=MOD;
    }

}

int32_t main()
{
    int m;
    cin>>n>>m;
    int s, t;
    cin>>s>>t;

    for(int i=0;i<m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    vector < int > dp1(n+1, 0);
    vector < int > dp2(n+1, 0);
    vector < int > dist1(n+1, 1e15);
    vector < int > dist2(n+1, 1e15);
    init(s, t, dp1, dist1);
    init(t, s, dp2, dist2);

    int ans = dp1[t]*dp1[t];
    ans%=MOD;
    int tot = dist1[t];
    tot/=2;
    for(int i=1;i<=n;i++)
    {
        if(dist1[i] == tot && dist2[i] == tot && dist1[i]+dist2[i] == dist1[t])
        {
            int temp = (dp1[i]*dp2[i])%MOD;
            temp*=dp1[i];
            temp%=MOD;
            temp*=dp2[i];
            temp%=MOD;
            ans-=temp;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            int w = a[i][j].second;
            int u = i;
            int v = a[i][j].first;
            if( dist1[u] < tot && dist2[v] < tot && (dist1[u]+dist2[v]+w) == dist1[t])
            {
                int temp = (dp1[u]*dp2[v])%MOD;
                temp*=dp1[u];
                temp%=MOD;
                temp*=dp2[v];
                temp%=MOD;
                ans-=temp;
                ans%=MOD;
            }
        }
    }
    ans = (ans % MOD + MOD ) %MOD;
    cout<<ans<<endl;

    return 0;
}