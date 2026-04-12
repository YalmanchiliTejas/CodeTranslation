//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

void mod_print(ll k){
    ll P=1000;
    rep(y,1,P){
        ll x=mod(y*k);
        if(x+P>=i_7){
            x-=i_7;
        }
        if(abs(x)<=P){
            cout<<x<<"/"<<y<<endl;
            return;
        }
    }
    cout<<"nun"<<endl;
}
//////////////////////////


#define N 200005
ll n,m;
ll s,t;
struct edge{
    ll to,cost;
};
vector<edge>v[N];
vector<ll> ds(N),dt(N);
vector<ll> ks(N),kt(N);
void dijk(ll sta,vector<ll>&d){
    priority_queue<l_l,vector<l_l>,greater<l_l>>q;
    rep(i,1,n)d[i]=inf;
    d[sta]=0;q.push({0,sta});
    while(!q.empty()){
        l_l top=q.top();q.pop();
        ll pos=top.se;
        for(auto x:v[pos]){
            if(chmin(d[x.to],d[pos]+x.cost)){
                q.push({d[x.to],x.to});
            }
        }
    }
}

void kazu(ll sta,vector<ll>&k,vector<ll>&d){
    vector<l_l>idx;
    rep(i,1,n)idx.pb({d[i],i});
    SORT(idx);
    k[sta]=1;
    for(auto zz:idx){
        ll pos=zz.se;
        for(auto e:v[pos]){
            if(d[e.to]+e.cost==d[pos])Add(k[pos],k[e.to]);
        }
    }
}

int main(){fastio
    cin>>n>>m;
    cin>>s>>t;
    rep(iz,1,m){
        ll a,b,c;cin>>a>>b>>c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    dijk(s,ds);
    dijk(t,dt);
   // rep(i,1,n)cout<<ds[i]<<" ";cout<<endl;
   // rep(i,1,n)cout<<dt[i]<<" ";cout<<endl;cout<<endl;
    kazu(s,ks,ds);
    kazu(t,kt,dt);
    //rep(i,1,n)cout<<ks[i]<<" ";cout<<endl;
    //rep(i,1,n)cout<<kt[i]<<" ";cout<<endl;cout<<endl;
    rep(i,1,n){
        ks[i]=mod(ks[i]);
        kt[i]=mod(kt[i]);
    }
    ll ans=mod(ks[t]*kt[s]);
    //cout<<ans<<endl;
    rep(i,1,n){
        if(ds[t]==ds[i]*2){
            Add(ans,-powl(mod(ks[i]*kt[i]),2));
        }
        for(auto x:v[i]){
            ll j=x.to;
            if(ds[i]+dt[i]==ds[t]&&ds[j]+dt[j]==ds[t]&&ds[i]+x.cost==ds[j]&&ds[i]*2<ds[t]&&ds[t]<ds[j]*2){
            //if(ds[i]+x.cost==ds[j]&&ds[i]*2<ds[t]&&dt[j]*2<ds[t]){
                Add(ans,-powl(mod(ks[i]*kt[j]),2));
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<mod(ans)<<endl;
    
    return 0;
}
/*
 4 2
 8 2
 8 6
 
 4 2
 8 3
 8 2
 8 6
 */
