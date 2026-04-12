#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int MOD = 1000000007;
template<typename T,T uku>
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
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}
};

//INSERT ABOVE HERE
const int MAX = 3030;
using M = Mint<int, 0>;
M po[MAX*MAX];
M pp[MAX];
M dp[MAX][MAX];

M fact[MAX],finv[MAX];
M C(int n,int k){
  if(n<k||k<0) return M(0);
  return fact[n]*finv[n-k]*finv[k];
}
M P(int n,int k){
  if(n<k||k<0) return M(0);
  return fact[n]*finv[n-k];
}
signed main(){
  int n;
  cin>>n>>MOD;

  po[0]=1;
  for(int i=1;i<MAX*MAX;i++) po[i]=po[i-1]+po[i-1];
  
  pp[0]=2;
  for(int i=1;i<MAX;i++) pp[i]=pp[i-1]*pp[i-1];

  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      dp[i][j]=0;

  fact[0]=1;
  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);
  finv[n]=M(1)/fact[n];
  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);
  
  dp[0][0]=1;
  for(int i=0;i+1<MAX;i++){
    for(int j=0;j+1<MAX;j++){
      dp[i+1][j+1]+=dp[i][j];
      dp[i][j+1]+=dp[i][j]*M(i+1);
    }
  }
  
  M ans(0);
  for(int x=0;x<=n;x++){
    int y=n-x;
    for(int i=0;i<=n;i++){
      M res(1);
      res*=C(n,x);
      res*=dp[i][x];
      res*=po[i*y];
      res*=pp[y];
      
      if(~x&1) ans+=res;
      else ans-=res;
    }
  }
  cout<<ans.v<<endl;
  return 0;
}
