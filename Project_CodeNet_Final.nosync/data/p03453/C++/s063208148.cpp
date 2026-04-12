#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lli = long long ;
using pii = pair<int,int>;
using pli = pair<lli,int>;

const int MOD=1e9+7;
const lli INF=1e15;

int n,m,vis[100001];
lli fcnt[100001],bcnt[100001];
lli fdist[100001],bdist[100001];
vector<pii> adj[100001];

void Dijk(int s,lli *dist,lli *cnt) {
    priority_queue<pli,vector<pli>,greater<pli>> que;
    que.push({0,s});
    fill(vis,vis+n+1,0);
    fill(dist,dist+n+1,INF);
    cnt[s]=1;
    dist[s]=0;

    while(!que.empty()) {
        int cur=que.top().se;que.pop();
        if(vis[cur]) continue;
        vis[cur]=1;
        for(auto &it:adj[cur]) {
            if(!vis[it.se] && dist[it.se] > dist[cur]+it.fi) {
                cnt[it.se]=cnt[cur];
                dist[it.se] = dist[cur]+it.fi;
                que.push({dist[it.se],it.se});
            } else if(dist[it.se]==dist[cur]+it.fi) {
                cnt[it.se] = (cnt[it.se] + cnt[cur])%MOD;
            }
        }
    }
}
lli pw(lli a) {return a*a%MOD;}

int main() {
    int s,t;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    
    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(pii(w,v));
        adj[v].push_back(pii(w,u));
    }

    Dijk(s,fdist,fcnt);
    Dijk(t,bdist,bcnt);

    lli d=fdist[t],ans=fcnt[t]*bcnt[s]%MOD;
    if(d%2==0) {
        for(int i=1;i<=n;i++) if(fdist[i]==d/2 && fdist[i]+bdist[i]==d) {
            ans = (ans - pw(fcnt[i]*bcnt[i]%MOD) + MOD)%MOD;
        }
    }
    for(int i=1;i<=n;i++) for(auto &it:adj[i]) {
        if(fdist[i]+bdist[it.se]+it.fi==d &&
                fdist[i]<=d/2 && bdist[it.se]<=d/2 &&
                (d%2==1 || (fdist[i]!=d/2 && bdist[it.se]!=d/2))) {
            ans = (ans - pw(fcnt[i]*bcnt[it.se]%MOD) + MOD)%MOD;
        }
    }
    printf("%lld\n",ans);
    
    return 0;
}
