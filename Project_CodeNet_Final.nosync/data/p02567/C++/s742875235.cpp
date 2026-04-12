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
const ll mod=1000000007;
// const ll mod=998244353;
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

ll sumdigits(ll n){
  ll ans=0;
  while(n){ans+=n%10;n/=10;}
  return ans;
}
template<class S,S(*op)(S,S),S(*e)()>struct segtree{
public:
  segtree():segtree(0){}
  segtree(int n):segtree(vector<S>(n,e())){}
  segtree(const vector<S>& v):_n(int(v.size())){
    log=0;
    while((1U<<log)<(unsigned int)(_n))++log;
    size=1<<log;
    d=vector<S>(size<<1,e());
    for(int i=0;i<_n;++i)d[size+i]=v[i];
    for(int i=size-1;i>=1;--i)update(i);
  }

  void set(int p,S x){
    assert(0<=p&&p<_n);
    p+=size;
    d[p]=x;
    for(int i=1;i<=log;++i)update(p>>i);
  }

  S get(int p){
    assert(0<=p&&p<_n);
    return d[p+size];
  }

  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=_n);
    S sml=e(),smr=e();
    l+=size;
    r+=size;

    while(l<r){
      if(l&1)sml=op(sml,d[l++]);
      if(r&1)smr=op(d[--r],smr);
      l>>=1;
      r>>=1;
    }
    return op(sml,smr);
  }

  S all_prod(){return d[1];}

  //f(e)=true
  template<bool(*f)(S)>int max_right(int l){
    return max_right(l,[](S x){return f(x);});
  }
  template<class F>int max_right(int l,F f){
    assert(0<=l&&l<=_n);
    assert(f(e()));
    if(l==_n)return _n;
    l+=size;
    S sm=e();
    do{
      while(~l&1)l>>=1;
      if(!f(op(sm,d[l]))){
        while(l<size){
          l<<=1;
          if(f(op(sm,d[l]))){
            sm=op(sm,d[l++]);
          }
        }
        return l-size;
      }
      sm=op(sm,d[l++]);
    }while((l&-l)!=l);
    return _n;
  }

  template<bool(*f)(S)>int min_left(int r){
    return min_left(r,[](S x){return f(x);});
  }
  template<class F>int min_left(int r,F f){
    assert(0<=r&&r<=_n);
    assert(f(e()));
    if(r==0)return 0;
    r+=size;
    S sm=e();
    do{
      --r;
      while(r>1&&(r&1))r>>=1;
      if(!f(op(d[r],sm))){
        while(r<size){
          r=r<<1|1;
          if(f(op(d[r],sm))){
            sm=op(d[r--],sm);
          }
        }
        return r+1-size;
      }
      sm=op(d[r],sm);
    }while((r&-r)!=r);
    return 0;
  }

private:
  int _n,size,log;
  vector<S> d;

  void update(int k){d[k]=op(d[k<<1],d[k<<1|1]);}
};
ll op(ll a,ll b){return max(a,b);}
ll e(){return -inf;}
ll x;
bool f(ll a){
  return a<x;
}
ll N,Q;
int main(){
  startupcpp();
  ll i,j;
  cin>>N>>Q;
  vec v(N);
  rep(i,N)cin>>v[i];
  segtree<ll,op,e> tree(v);
  while(Q--){
    cin>>i;
    if(i==1){
      cin>>i>>x;tree.set(--i,x);
    }else if(i==2){
      cin>>i>>j;print(tree.prod(--i,j));
    }else{
      cin>>i>>x;print(tree.max_right<f>(--i)+1);
    }
  }
}