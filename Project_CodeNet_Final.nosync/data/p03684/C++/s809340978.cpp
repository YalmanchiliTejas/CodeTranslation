#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1LL<<60;
long double pi=3.14159265358979323846L;
double eps=1e-12;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll popcount(ll n){
    ll ret=0;
    while(n>0){
        ret+=n%2;
        n/=2;
    }
    return ret;
}
ll gya[1000010];
ll kai[1000010];
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll par[800010];
ll len[800010];
ll you[800010];
void init(ll n){
  for(int i=0;i<n;i++){
    par[i]=i;
    len[i]=0;
    you[i]=1;
  }
}
ll root(ll n){
  if(par[n]==n)return n;
  return par[n]=root(par[n]);
}
void unit(ll a,ll b){
  a=root(a);
  b=root(b);
  if(a==b)return;
  if(len[a]<len[b]){
    par[a]=b;
    you[b]+=you[a];
  }
  else{
    par[b]=a;
    you[a]+=you[b];
    if(len[a]==len[b])len[a]++;
  }
}
struct edge{
    ll from,to,cost;
};
bool cmp(edge &a,edge &b){
    return a.cost<b.cost;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    init(n+1);
    vector<pll> v,w;
    rep(i,0,n){
        ll x,y;cin>>x>>y;
        v.push_back({x,i});
        w.push_back({y,i});
    }
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());
    vector<edge> vv;
    rep(i,1,v.size()){
        vv.push_back((edge){v[i-1].second,v[i].second,v[i].first-
            v[i-1].first});
    }
    rep(i,1,w.size()){
        vv.push_back((edge){w[i-1].second,w[i].second,w[i].first-
            w[i-1].first});
    }
    sort(vv.begin(),vv.end(),cmp);
    ll ans=0;
    rep(i,0,vv.size()){
        edge e=vv[i];
        ll f=e.from,g=e.to,co=e.cost;
        if(root(f)==root(g))continue;
        ans+=co;
        unit(f,g);
    }
    cout<<ans<<endl;
}


