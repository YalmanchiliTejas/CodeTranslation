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


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}


//INSERT ABOVE HERE

signed main(){
  using M = Mint<Int>;
 
  Int n,m;
  cin>>n>>m;

  string s;
  cin>>s;

  vector<Int> vs(m);
  for(Int i=0;i<m;i++)
    vs[i]=(s[0]!='R')^(s[i]=='R');

  for(Int i=0;i<m;i++)
    s[i]="BR"[vs[i]];
  
  if(vs==vector<Int>(m,1)){    
    auto dp=make_v<M>(2,2,n+1);
    fill_v<M>(dp,M(0));
    dp[0][0][1]=M(1);
    dp[1][1][1]=M(1);

    for(Int i=1;i<n;i++)
      for(Int j=0;j<2;j++)
        for(Int k=0;k<2;k++)
          for(Int l=0;l<2;l++)
            if(k||l) dp[j][l][i+1]+=dp[j][k][i];    

    M ans{0};
    for(Int j=0;j<2;j++)
      for(Int k=0;k<2;k++)
        if(j||k) ans+=dp[j][k][n];

    cout<<ans.v<<endl;
    return 0;
  }
  assert(vs!=vector<Int>(m,0));

  if(n&1){
    cout<<0<<endl;
    return 0;
  }
  
  Int lim=n-1;  
  for(Int i=0;i<m;i++){
    if(s[i]=='B') continue;
    Int j=i;
    while(j<m&&s[j]=='R') j++;
    if(j==m) break;

    if(i==0&&(j-i)%2==0) chmin(lim,j-i+1);
    if((j-i)&1) chmin(lim,j-i);    
    i=j-1;
  }
  
  vector<M> dp(n+2,0),sm(n+2,0);
  dp[1]=M(1);  
  for(Int i=2;i<=n+1;i++){
    sm[i]=sm[i-1]+dp[i-1];
    if(i&1) dp[i]=sm[i-1]-sm[max<Int>(1,i-1-lim)];
  }
  
  M ans{0};
  for(Int i=0;i<=lim;i++)
    ans+=sm[n-i+1]-sm[max<Int>(1,n-lim)];
  
  cout<<ans.v<<endl;
  return 0;
}
