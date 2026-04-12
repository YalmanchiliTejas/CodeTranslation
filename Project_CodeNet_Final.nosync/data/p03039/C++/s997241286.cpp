#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T,T MOD = 1000000007>
struct Mint{
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
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  // find x s.t. a^x = b
  static T log(Mint a,Mint b){
    const T sq=40000;
    unordered_map<T, T> dp;
    dp.reserve(sq);
    Mint res(1);
    for(Int r=0;r<sq;r++){
      if(!dp.count(res.v)) dp[res.v]=r;
      res*=a;
    }
    Mint p=a.inv().pow(sq);
    res=b;
    for(Int q=0;q<=MOD/sq+1;q++){
      if(dp.count(res.v)){
        T idx=q*sq+dp[res.v];
        if(idx>0) return idx;
      }
      res*=p;
    }
    assert(0);
    return T(-1);
  }
  
  static Mint comb(long long n,Int k){
    Mint res(1);
    for(Int i=0;i<k;i++){
      res*=Mint(n-i);
      res/=Mint(i+1);
    }
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  Int h,w,k;
  cin>>h>>w>>k;
  using M = Mint<Int>;

  M ans{0};
  for(Int d=1;d<h;d++)
    ans+=M(d)*M(h-d)*M(w)*M(w);

  for(Int d=1;d<w;d++)
    ans+=M(d)*M(w-d)*M(h)*M(h);
  
  ans*=M::comb(h*w-2,k-2);
  cout<<ans.v<<endl;
  return 0;
}
