#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
// const ll mod=1000000007;
const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

double distance(ddatas x,ddatas y){
  double a=x.first-y.first,b=x.second-y.second;
  return sqrt(a*a+b*b);
}

ll modinv(ll a,ll m=mod) {
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
}

ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}

vec modncrlistp,modncrlistm;

ll modncr(ll n,ll r){
  if(n<r)return 0;
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1){
      modncrlistp[i]=modncrlistp[i-1]*i%mod;
      modncrlistm[i]=modinv(modncrlistp[i]);
    }
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,ll m=mod){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%m;
    a=a*a%m;
    n>>=1;
  }
  return res;
}

ll gcd(ll a,ll b){if(!b)return abs(a);return (a%b==0)?abs(b):gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll countdigits(ll n){
  ll ans=0;
  while(n){n/=10;ans++;}
  return ans;
}

template<typename T>
struct LazySegmentTree{
private:
  using func=function<T(T,T)>;
  func f,g;
  size_t N=1;
  T E;
  vector<T> node,lazy;
  vector<bool> vis;
  void eval(size_t& x){
    if(!vis[x])return;
    node[x]=g(node[x],lazy[x]);
    vis[x]=false;
    if(x<N){
      if(vis[x<<1])lazy[x<<1]=g(lazy[x<<1],lazy[x]);
      else{
        lazy[x<<1]=lazy[x];
        vis[x<<1]=true;
      }
      if(vis[x<<1|1])lazy[x<<1|1]=g(lazy[x<<1|1],lazy[x]);
      else{
        lazy[x<<1|1]=lazy[x];
        vis[x<<1|1]=true;
      }
    }
  }
  void update(size_t& a,size_t& b,T& x,size_t now,size_t l,size_t r){
    eval(now);
    if((b<=l)|(r<=a))return;
    if((a<=l)&(r<=b)){
      vis[now]=true;lazy[now]=x;
      eval(now);
    }else{
      update(a,b,x,now<<1,l,(l+r)>>1);
      update(a,b,x,now<<1|1,(l+r)>>1,r);
      node[now]=f(node[now<<1],node[now<<1|1]);
    }
  }
  T call(size_t& a,size_t &b,size_t now,size_t l,size_t r){
    eval(now);
    if((b<=l)|(r<=a))return E;
    if((a<=l)&(r<=b))return node[now];
    return f(call(a,b,now<<1,l,(l+r)>>1),call(a,b,now<<1|1,(l+r)>>1,r));
  }
public:
  LazySegmentTree(vector<T>& v,func F,func G,T Ie):f(F),g(G),E(Ie){
    size_t i=v.size();
    while(i){
      N<<=1;i>>=1;
    }
    node.resize(N<<1,E);
    lazy.resize(N<<1);
    vis.resize(N<<1,false);
    for(i=0;i<v.size();i++){
      node[N+i]=v[i];
    }
    for(i=N;i--;){
      node[i]=f(node[i<<1],node[i<<1|1]);
    }
  }
  //do g(p,x). p is all[a,b);
  void update(size_t a,size_t b,T x){
    if(a<b)update(a,b,x,1,0,N);
  }
  //get f(I) I=[a,b);
  T get(size_t a,size_t b){
    return call(a,b,1,0,N);
  }
};
ll p(ll a,ll b){
  return (a+b)%mod;
}
ll N,X,M,ans;
int main(){
  startupcpp();
  ll i;
  cin>>N>>X>>M;
  vec next(M);
  rep(i,M){
    next[i]=i*i%M;
  }
  if(N<1e6){
    while(N--){
      ans+=X;
      X=next[X];
    }
    print(ans);
    return 0;
  }
  set<ll> se;
  while(N--&&se.insert(X).second){
    ans+=X;
    X=next[X];
  }
  if(++N==0){
    print(ans);
    return 0;
  }
  se.clear();
  vec v;
  while(N--&&se.insert(X).second){
    v.eb(X);
    ans+=X;
    X=next[X];
  }
  if(++N==0){
    print(ans);
    return 0;
  }
  vec sum(1,0);
  rep1(i,v.size()){
    v[i]+=v[i-1];
  }
  for(auto x:v)sum.eb(x);
  print(ans+N/v.size()*v.back()+sum[N%v.size()]);
}