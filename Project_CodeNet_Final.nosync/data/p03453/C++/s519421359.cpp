#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;

const int INF=1001001001001001001ll;

inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int N,M;
int S,T;
vpint G[222222];
int U[222222],V[222222],D[222222];

vpint dijkstra(int s){
    vpint dist(N,pint(INF,1));
    dist[s]={0,1};
    priority_queue<pint,vector<pint>,greater<pint>>que;
    que.push({0,s});
    while(que.size()){
        int c,v;
        tie(c,v)=que.top();
        que.pop();
        if(dist[v].fi<c)continue;
        for(auto &e:G[v]){
            if(dist[e.fi].fi<c+e.se)continue;
            if(dist[e.fi].fi==c+e.se){
                add(dist[e.fi].se,dist[v].se);
            }
            else{
                dist[e.fi]=dist[v];
                dist[e.fi].fi+=e.se;
                que.push({dist[e.fi].fi,e.fi});
            }
        }
    }
    return dist;
}

signed main(){
    cin>>N>>M>>S>>T;S--;T--;
    rep(i,M){
        cin>>U[i]>>V[i]>>D[i];
        U[i]--;V[i]--;
        G[U[i]].pb({V[i],D[i]});G[V[i]].pb({U[i],D[i]});
    }

    vpint distS=dijkstra(S);
    vpint distT=dijkstra(T);

    int ans=distS[T].se;
    ans=ans*ans%mod;

    rep(i,N){
        if(distS[i].fi+distT[i].fi!=distS[T].fi||distS[i].fi!=distT[i].fi)continue;
        int tmp=distS[i].se*distT[i].se%mod;
        ans=(ans-tmp*tmp%mod+mod)%mod;
    }

    rep(i,M){
        int u,v,d;
        u=U[i];
        v=V[i];
        d=D[i];
        rep(ei,2){
            swap(u,v);
            if(distS[u].fi+distT[v].fi+d!=distS[T].fi)continue;
            if(!(distS[u].fi*2<distS[T].fi&&distS[v].fi*2>distS[T].fi))continue;
            int tmp=distS[u].se*distT[v].se%mod;
            ans=(ans-tmp*tmp%mod+mod)%mod;
        }
    }

    cout<<ans<<endl;
    return 0;
}
