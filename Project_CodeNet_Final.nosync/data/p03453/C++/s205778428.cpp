#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair

const ll MaxN=100001;
ll N,M,S,T;
vector<P> d[MaxN];
ll ds[MaxN];
ll dpS[MaxN], dpT[MaxN];

vec Use[MaxN];

int main(){
    cin>>N>>M>>S>>T;
    S--; T--;
    rep(i,M){
        ll u,v,x; cin>>u>>v>>x;
        u--; v--;
        d[u].pb(mp(x,v));
        d[v].pb(mp(x,u));
    }

    P_queue Q;
    Q.push(mp(0,S));
    rep(i,MaxN) if(i!=S) ds[i]=INF;
    while(!Q.empty()){
        ll x=Q.top().first, y=Q.top().second;
        Q.pop();
        rep(i,d[y].size()){
            ll X=d[y].at(i).first, Y=d[y].at(i).second;
            if(ds[Y]>x+X){
                ds[Y]=x+X;
                Q.push(mp(x+X,Y));
            }
        }
    }

    ll DIST=ds[T];

    vector<P> hiku;
    rep(i,N) {
        rep(j,d[i].size()){
            ll a=d[i].at(j).first, b=d[i].at(j).second;
            ll PU=0;
            if(ds[b]==ds[i]+a) PU=1;;
            if(ds[i]==ds[b]+a) PU=-1;
            if(ds[b]==ds[i]+a && ds[b]*2>DIST && ds[i]*2<DIST) PU=2;
            if(ds[i]==ds[b]+a && ds[b]*2<DIST && ds[i]*2>DIST) PU=-2;
            Use[i].pb(PU);
            if(PU==2) hiku.pb(mp(i,b));
        }
        if(ds[i]*2==DIST) hiku.pb(mp(i,i));
    }// 1のときはS→Tのときに使える辺、-1のときはT→S

    vector<P> K;
    rep(i,N) if(ds[i]<ds[T] || i==T) K.pb(mp(ds[i],i));
    sort(K.begin(),K.end());

    ll n=K.size();
    dpS[S]=1;
    dpT[T]=1;

    rep(j,n){
        ll i=K.at(j).second;
        dpS[i]=dpS[i]%mod;
        rep(k,Use[i].size()) if(Use[i].at(k)>0) dpS[d[i].at(k).second]+=dpS[i];
    }

    rep(j,n){
        ll i=K.at(n-1-j).second;
        dpT[i]=dpT[i]%mod;
        rep(k,Use[i].size()) if(Use[i].at(k)<0) dpT[d[i].at(k).second]+=dpT[i];
    }

    ll ans=(dpS[T]*dpT[S])%mod;

    ll HIKU=0;
    rep(i,hiku.size()) {
        ll AA=(dpS[hiku.at(i).first]*dpT[hiku.at(i).second])%mod;
        HIKU=(HIKU+AA*AA)%mod;
    }
    ans=(ans+mod-HIKU)%mod;
    cout<<ans<<endl;




}
