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
ll inf=1000000000000000000;
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
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    ll a[n],b[n];
    vector<pll> v;
    rep(i,0,n){
        cin>>a[i]>>b[i];
        if(a[i]>b[i])swap(a[i],b[i]);
        v.push_back({a[i],i});
        v.push_back({b[i],i});
    }
    sort(v.begin(),v.end());
    ll one[2*n];
    bool used[n];
    fill(used,used+n,false);
    ll e[n][2];
    rep(i,0,v.size()){
        ll num=v[i].second;
        if(used[num]){
            one[i]=1;
            e[num][1]=i;
        }
        else{
            one[i]=0;
            used[num]=true;
            e[num][0]=i;
        }
    }
    
    ll rm=0,rmi=inf,bm=0,bmi=inf;
    rep(i,0,2*n){
        if(one[i]==0){
            bm=max(bm,v[i].first);
            bmi=min(bmi,v[i].first);
        }
        else if(one[i]==1){
            rm=max(rm,v[i].first);
            rmi=min(rmi,v[i].first);
        }
    }
    ll ans=(rm-rmi)*(bm-bmi);
    fill(used,used+n,false);
    used[v[2*n-1].second]=true;
    rep(i,0,2*n){
        ans=min(ans,(bm-v[i].first)*(rm-rmi));
        ll num=v[i].second;
        if(used[num])break;
        ll f=e[num][0],g=e[num][1];
        bm=max(bm,v[g].first);
        rmi=min(rmi,v[f].first);
        used[num]=true;
    }
    cout<<ans<<endl;
}
