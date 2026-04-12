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

//INSERT ABOVE HERE
using M = Mint<int>;
const int MAX = 1010;
int dp[MAX][MAX];
M sm[MAX][MAX]={};

signed main(){
  int h,w;
  cin>>h>>w;
  h++;w++;

  for(int i=0;i<MAX;i++)
    dp[0][i]=dp[i][0]=i;

  for(int i=1;i<MAX;i++)
    for(int j=1;j<MAX;j++)
      dp[i][j]=dp[min(i,j)][min(i%j,j%i)];

  for(int i=1;i<MAX;i++)
    for(int j=1;j<MAX;j++)
      sm[i][j]=sm[i][j-1]+M(dp[i][j]-1);

  for(int i=1;i<MAX;i++)
    for(int j=1;j<MAX;j++)
      sm[i][j]+=sm[i-1][j];

  int num=h*w;
  M ans=M(num)*M(num-1)*M(num-2)/M(6);
  //cout<<ans<<endl;

  for(int i=1;i<h;i++)
    for(int j=1;j<w;j++)
      ans-=M(2)*sm[i][j];
  //cout<<ans<<endl;

  ans-=M(h)*M(h-1)*M(h-2)/M(6)*M(w);
  ans-=M(w)*M(w-1)*M(w-2)/M(6)*M(h);
  //cout<<ans<<endl;

  ans*=M(2).pow(num-3);
  cout<<ans<<endl;
  return 0;
}

