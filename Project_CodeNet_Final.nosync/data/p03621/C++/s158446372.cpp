#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T,T MOD = 1000000007>
struct Mint{
  static constexpr T mod = MOD;
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;}
  Mint operator-(Mint a) const{return Mint(v)-=a;}
  Mint operator*(Mint a) const{return Mint(v)*=a;}
  Mint operator/(Mint a) const{return Mint(v)/=a;}

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  static Mint comb(long long n,int k){
    Mint num(1),dom(1);
    for(int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}


constexpr int bmds(int x){
  const int v[] = {1012924417, 924844033, 998244353,
                   897581057, 645922817};
  return v[x];
}
constexpr int brts(int x){
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template<int X>
struct NTT{
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = Mint<int, md>;
  vector< vector<M> > rts,rrts;

  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      M w=M(rt).pow((md-1)/(i<<1));
      M rw=w.inv();
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=M(1);rrts[i][0]=M(1);
      for(int k=1;k<i;k++){
        rts[i][k]=rts[i][k-1]*w;
        rrts[i][k]=rrts[i][k-1]*rw;
      }
    }
  }

  void ntt(vector<M> &as,bool f){
    int n=as.size();
    assert((n&(n-1))==0);
    ensure_base(n);

    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(as[i],as[j]);
    }

    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
        for(int k=0;k<i;k++){
          M z=as[i+j+k]*(f?rrts[i][k]:rts[i][k]);
          as[i+j+k]=as[j+k]-z;
          as[j+k]+=z;
        }
      }
    }

    if(f){
      M tmp=M(n).inv();
      for(int i=0;i<n;i++) as[i]*=tmp;
    }
  }

  vector<M> multiply(vector<M> as,vector<M> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    as.resize(sz,M(0));
    bs.resize(sz,M(0));

    ntt(as,0);ntt(bs,0);
    for(int i=0;i<sz;i++) as[i]*=bs[i];
    ntt(as,1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as,vector<int> bs){
    vector<M> am(as.size()),bm(bs.size());
    for(int i=0;i<(int)am.size();i++) am[i]=M(as[i]);
    for(int i=0;i<(int)bm.size();i++) bm[i]=M(bs[i]);
    vector<M> cm=multiply(am,bm);
    vector<int> cs(cm.size());
    for(int i=0;i<(int)cs.size();i++) cs[i]=cm[i].v;
    return cs;
  }
};
template<int X> constexpr int NTT<X>::md;
template<int X> constexpr int NTT<X>::rt;


template<typename T>
struct FormalPowerSeries{
  using Poly = vector<T>;
  using Conv = function<Poly(Poly, Poly)>;
  Conv conv;
  FormalPowerSeries(Conv conv):conv(conv){}

  Poly pre(const Poly &as,int deg){
    return Poly(as.begin(),as.begin()+min((int)as.size(),deg));
  }

  Poly add(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
    return cs;
  }

  Poly sub(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
    return cs;
  }

  Poly mul(Poly as,Poly bs){
    return conv(as,bs);
  }

  Poly mul(Poly as,T k){
    for(auto &a:as) a*=k;
    return as;
  }

  // F(0) must not be 0
  Poly inv(Poly as,int deg){
    assert(as[0]!=T(0));
    Poly rs({T(1)/as[0]});
    for(int i=1;i<deg;i<<=1)
      rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);
    return rs;
  }

  // not zero
  Poly div(Poly as,Poly bs){
    while(as.back()==T(0)) as.pop_back();
    while(bs.back()==T(0)) bs.pop_back();
    if(bs.size()>as.size()) return Poly();
    reverse(as.begin(),as.end());
    reverse(bs.begin(),bs.end());
    int need=as.size()-bs.size()+1;
    Poly ds=pre(mul(as,inv(bs,need)),need);
    reverse(ds.begin(),ds.end());
    return ds;
  }

  // F(0) must be 1
  Poly sqrt(Poly as,int deg){
    assert(as[0]==T(1));
    T inv2=T(1)/T(2);
    Poly ss({T(1)});
    for(int i=1;i<deg;i<<=1){
      ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);
      for(T &x:ss) x*=inv2;
    }
    return ss;
  }

  Poly diff(Poly as){
    int n=as.size();
    Poly rs(n-1);
    for(int i=1;i<n;i++) rs[i-1]=as[i]*T(i);
    return rs;
  }

  Poly integral(Poly as){
    int n=as.size();
    Poly rs(n+1);
    rs[0]=T(0);
    for(int i=0;i<n;i++) rs[i+1]=as[i]/T(i+1);
    return rs;
  }

  // F(0) must be 1
  Poly log(Poly as,int deg){
    return pre(integral(mul(diff(as),inv(as,deg))),deg);
  }

  // F(0) must be 0
  Poly exp(Poly as,int deg){
    Poly f({T(1)});
    as[0]+=T(1);
    for(int i=1;i<deg;i<<=1)
      f=pre(mul(f,sub(pre(as,i<<1),log(f,i<<1))),i<<1);
    return f;
  }

  Poly partition(int n){
    Poly rs(n+1);
    rs[0]=T(1);
    for(int k=1;k<=n;k++){
      if(1LL*k*(3*k+1)/2<=n) rs[k*(3*k+1)/2]+=T(k%2?-1LL:1LL);
      if(1LL*k*(3*k-1)/2<=n) rs[k*(3*k-1)/2]+=T(k%2?-1LL:1LL);
    }
    return inv(rs,n+1);
  }

  Poly bernoulli(int n){
    Poly rs(n+1,1);
    for(int i=1;i<=n;i++) rs[i]=rs[i-1]/T(i+1);
    rs=inv(rs,n+1);
    T tmp(1);
    for(int i=1;i<=n;i++){
      tmp*=T(i);
      rs[i]*=tmp;
    }
    return rs;
  }
};


template<typename M>
class Enumeration{
private:
  static vector<M> fact,finv,invs;
public:
  static void init(int n){
    n=min<decltype(M::mod)>(n,M::mod-1);

    int m=fact.size();
    if(n<m) return;

    fact.resize(n+1,1);
    finv.resize(n+1,1);
    invs.resize(n+1,1);

    if(m==0) m=1;
    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);
    finv[n]=M(1)/fact[n];
    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);
    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }

  static M Fact(int n){
    init(n);
    return fact[n];
  }
  static M Finv(int n){
    init(n);
    return finv[n];
  }
  static M Invs(int n){
    init(n);
    return invs[n];
  }

  static M C(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static M P(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k];
  }

  static M H(int n,int k){
    if(n<0||k<0) return M(0);
    if(!n&&!k) return M(1);
    init(n+k-1);
    return C(n+k-1,k);
  }

  static M S(int n,int k){
    init(k);
    M res(0);
    for(int i=1;i<=k;i++){
      M tmp=C(k,i)*M(i).pow(n);
      if((k-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res*=finv[k];
  }

  static vector< vector<M> > D(int n,int m){
    vector< vector<M> > dp(n+1,vector<M>(m+1,0));
    dp[0][0]=M(1);
    for(int i=0;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(i-j>=0) dp[i][j]=dp[i][j-1]+dp[i-j][j];
        else dp[i][j]=dp[i][j-1];
      }
    }
    return dp;
  }

  static M B(int n,int k){
    if(n==0) return M(1);
    k=min(k,n);
    init(k);
    vector<M> dp(k+1);
    dp[0]=M(1);
    for(int i=1;i<=k;i++)
      dp[i]=dp[i-1]+((i&1)?-finv[i]:finv[i]);
    M res(0);
    for(int i=1;i<=k;i++)
      res+=M(i).pow(n)*finv[i]*dp[k-i];
    return res;
  }

  static M montmort(int n){
    init(n);
    M res(0);
    for(int k=2;k<=n;k++){
      if(k&1) res-=finv[k];
      else res+=finv[k];
    }
    return res*=fact[n];
  }

  static M LagrangePolynomial(vector<M> &y,M t){
    int n=y.size()-1;
    if(t.v<=n) return y[t.v];
    init(n+1);
    vector<M> dp(n+1,1),pd(n+1,1);
    for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
    for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));
    M res(0);
    for(int i=0;i<=n;i++){
      M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
      if((n-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res;
  }
};
template<typename M>
vector<M> Enumeration<M>::fact=vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv=vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs=vector<M>();

//INSERT ABOVE HERE
signed main(){
  string a,b;
  cin>>a>>b;
  int n=a.size();
  int m=count(a.begin(),a.end(),'1');

  NTT<2> ntt;
  using M = decltype(ntt)::M;
  using E = Enumeration<M>;
  E::init(1e6);
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);
  using Poly = decltype(FPS)::Poly;

  int p=0,q=0;
  for(int i=0;i<n;i++){
    if(a[i]=='1'&&b[i]=='0') p++;
    if(a[i]=='1'&&b[i]=='1') q++;
  }

  const int deg = 1<<15;
  Poly qs(q+1);
  for(int i=0;i<=q;i++) qs[i]=E::Finv(i+1);
  qs=FPS.exp(FPS.mul(FPS.log(qs,deg),M(p)),deg);

  M ans{0};
  for(int i=0;i<=q;i++) ans+=qs[i];
  ans*=E::Fact(p)*E::Fact(q)*E::Fact(m);

  cout<<ans<<endl;
  return 0;
}
