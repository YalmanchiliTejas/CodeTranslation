#include <bits/stdc++.h>
using namespace std;
using ll= long long ;
using P = pair<ll,ll>;
#define rep(i,n) for (ll i = 0; i<(ll)(n); i++)
#define mod 998244353
#define pi 3.141592653589793
typedef vector<ll> vcl;

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t =rep_jijo(n,x/2);
        return t*t%mod;
  }
  return n*rep_jijo(n,x-1)%mod;
}
ll c2(ll n){
    return n*(n-1)/2;
}
  struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};
int main(){
 ll n,x,m;
 cin>>n>>x>>m;
 map<ll,ll> mp;
 map<ll,ll> mq;
 ll p = min(n,m);
 vcl a(p);
 ll z = 0,y = 0,an = x;
 a[1]=x;
 mp[x]=1;
 mq[x]=1;
 for (ll i=2;i<=n;i++){
   x=(x*x)%m  ;
   a[i] = x;
   if(mp[x]==1){ 
     y = i;
     z = mq[x];
     
     break;
   }
    mq[x] = i;
    mp[x] = 1;
    an+=x;
 }

if(z==0){cout<<an<<endl; return 0;}

ll ans1=0,ans2=0;
 for(ll i=1;i<=z-1;i++){
   ans1+=a[i];
 }
 ll kk=(n+1-z)%(y-z);
 ll k =((n+1-z)-kk)/(y-z);

 for(ll i=z;i<=y-1;i++){
   ans2+=a[i];
 }

ll ans = ans1+k*ans2;
for(ll i=z;i<=z+kk-1;i++){
  ans+=a[i];}

cout<<ans<<endl;
}


