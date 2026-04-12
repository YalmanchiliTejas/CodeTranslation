#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=1e5+10;
    const ll MOD=1e9+7;
    int N,M,S,T;
    ll d1[MAXN],d2[MAXN];
    ll dp1[MAXN],dp2[MAXN];
    int vis[MAXN];
    vector<pair<int,ll>>G[MAXN];
    struct Node
    {
        int k;
        ll v;
        Node(int _k,ll _v){
            k=_k;
            v=_v;
        }
        bool operator<(const Node &n)const{
            return v>n.v;
        }
    };
    void dijstra(int start,int end,ll d[],ll dp[]){
        memset(d,0x3f,MAXN*8);
        priority_queue<Node>pq;
        d[start]=0;
        dp[start]=1;
        pq.push(Node(start,0));
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            if(vis[p.k])continue;
            vis[p.k]=true;
            for(auto e:G[p.k]){
                if(d[p.k]+e.second<d[e.first]){
                    d[e.first]=d[p.k]+e.second;
                    dp[e.first]=dp[p.k];
                    pq.push(Node(e.first,d[e.first]));
                }
                else if(d[p.k]+e.second==d[e.first]){
                    dp[e.first]=(dp[e.first]+dp[p.k])%MOD;
                }
            }
        }
    }

    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>N>>M>>S>>T;
        for(int k=0;k<M;k++){
            int u,v;
            ll d;
            cin>>u>>v>>d;
            G[u].push_back({v,d});
            G[v].push_back({u,d});
        }
        dijstra(S,T,d1,dp1);
        memset(vis,0,sizeof(vis));
        dijstra(T,S,d2,dp2);
        ll ans=(dp1[T]*dp1[T])%MOD;
        ll pL=d1[T];
        for(int v=1;v<=N;v++){
            if(d1[v]*2==pL&&d2[v]*2==pL){
                ans=(ans-dp1[v]*dp2[v]%MOD*dp1[v]%MOD*dp2[v]%MOD+MOD)%MOD;
            }
        }
        for(int u=1;u<=N;u++){
            for(auto e:G[u]){
                int v=e.first;
                ll d=e.second;
                if(d1[u]*2<pL&&d2[v]*2<pL
                &&d1[u]+d2[v]+d==pL){
                    ans=(ans-dp1[u]*dp2[v]%MOD*dp1[u]%MOD*dp2[v]%MOD+MOD)%MOD;
                }
            }
        }
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}
