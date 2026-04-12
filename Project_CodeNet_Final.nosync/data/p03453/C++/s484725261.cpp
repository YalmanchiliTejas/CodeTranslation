#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
const long long mod=1000000007;
const long long inf=0x3f3f3f3f3f3f3f3f;
const int maxn=112345;
const int maxm=212345;
int n,m,s,t,u[maxm],v[maxm],w[maxm];
long long d[2][maxn],dp[2][maxn];
vector<pii> G[maxn];
inline void dijkstra(int s,long long *d,long long *dp) {
    for (int i=1;i<=n;++i) d[i]=inf;
    priority_queue<pli,vector<pli>,greater<pli> > que;
    d[s]=0;
    dp[s]=1;
    que.push(pli(0,s));
    while (!que.empty()) {
        int u=que.top().second;
        long long o=que.top().first;
        que.pop();
        if (o>d[u]) continue;
        for (int i=0;i<(int)G[u].size();++i) {
            int v=G[u][i].first;;
            int w=G[u][i].second;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                dp[v]=dp[u];
                que.push(pli(d[v],v));
            } else if (d[v]==d[u]+w) dp[v]=(dp[v]+dp[u])%mod;

        }
    }
}
inline long long sqr(long long x) {
    return x*x%mod;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (int i=1;i<=m;++i) {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        G[u[i]].push_back(pii(v[i],w[i]));
        G[v[i]].push_back(pii(u[i],w[i]));
    }
    dijkstra(s,d[0],dp[0]);
    dijkstra(t,d[1],dp[1]);
    long long res=sqr(dp[0][t]);
    for (int i=1;i<=n;++i) if (d[0][i]+d[1][i]==d[0][t]&&d[0][i]==d[1][i])
        res=((res-sqr(dp[0][i])*sqr(dp[1][i])%mod)%mod+mod)%mod;
    for (int i=1;i<=m;++i) for (int j=0;j<2;++j) {
        if (d[0][u[i]]+d[1][v[i]]+w[i]==d[0][t]
            &&d[0][v[i]]>d[1][v[i]]
            &&d[1][u[i]]>d[0][u[i]])
            res=((res-sqr(dp[0][u[i]])*sqr(dp[1][v[i]])%mod)%mod+mod)%mod;
        swap(u[i],v[i]);
    }
    cout<<res<<endl;
    return 0;
}
