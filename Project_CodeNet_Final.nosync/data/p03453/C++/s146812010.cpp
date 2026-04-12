#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;

vector<pair<int,ll>> S[MAX];
ll dis[MAX][2],pat[MAX][2];
int seen[MAX][2];

void dijkstra(int u,int q){
    dis[u][q]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    
    PQ.push(make_pair(0,u));
    while(!PQ.empty()){
        ll a=PQ.top().first;
        int b=PQ.top().second;
        PQ.pop();
        if(dis[b][q]<a) continue;
        for(int i=0;i<S[b].size();i++){
            int c=S[b][i].first;
            ll d=S[b][i].second;
            if(dis[c][q]>dis[b][q]+d){
                dis[c][q]=dis[b][q]+d;
                PQ.push(make_pair(dis[c][q],c));
            }
        }
    }
    return;
}//a,dが長さ

void count(int u,int q){
    ll sum=pat[u][q];
    for(int i=0;i<S[u].size();i++){
        int a=S[u][i].first;ll b=S[u][i].second;
        if(dis[u][q]<=dis[a][q]||dis[u][q]!=dis[a][q]+b) continue;
        if(seen[a][q]) sum+=pat[a][q];
        else{
            count(a,q);
            sum+=pat[a][q];
        }
        sum%=mod;
    }
    pat[u][q]=sum;
    seen[u][q]=1;
}

struct edge{
    int s;
    int t;
    ll d;
};

int main(){
    
    int N,M,A,B;cin>>N>>M>>A>>B;
    A--;B--;
    
    vector<edge> G(M*2);
    
    for(int i=0;i<M;i++){
        int s,t;
        ll d;cin>>s>>t>>d;
        s--;t--;
        G[i]={s,t,d};
        G[i+M]={t,s,d};
        S[s].push_back({t,d});
        S[t].push_back({s,d});
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        dis[i][0]=INF;
        dis[i][1]=INF;
    }
    
    dijkstra(A,0);
    dijkstra(B,1);
    pat[A][0]=1;
    pat[B][1]=1;
    count(B,0);
    count(A,1);
    
    ll maxi=dis[B][0];
    
    if(maxi%2==0){
        for(int i=0;i<N;i++){
            if(dis[i][0]==maxi/2&&dis[i][1]==maxi/2){
                ans+=pat[i][0]*pat[i][1]%mod*pat[i][0]%mod*pat[i][1]%mod;
                ans%=mod;
            }
        }
    }
    
    for(int i=0;i<M*2;i++){
        if(dis[G[i].s][0]+G[i].d==dis[G[i].t][0]&&dis[G[i].t][1]+G[i].d==dis[G[i].s][1]&&dis[G[i].s][0]*2<maxi&&maxi<dis[G[i].t][0]*2&&dis[G[i].t][1]*2<maxi&&maxi<dis[G[i].t][0]*2){
            ans+=pat[G[i].s][0]*pat[G[i].t][1]%mod*pat[G[i].s][0]%mod*pat[G[i].t][1]%mod;
            ans%=mod;
        }
        //cout<<ans<<endl;
    }
    
    cout<<((pat[B][0]*pat[B][0])%mod+mod-ans)%mod<<endl;
}

