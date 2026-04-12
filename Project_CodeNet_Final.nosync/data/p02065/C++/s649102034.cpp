#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int MOD = 1000000007;
template<typename T>
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
};
template<typename T>
ostream& operator<<(ostream &os,Mint<T> m){os<<m.v;return os;}

//INSERT ABOVE HERE

using M = Mint<int>;
M dp[202][11][1<<10]={};
M nx[202][11][1<<10]={};

signed main(){
  int n,k;
  cin>>n>>k>>MOD;

  for(int i=0;i<k;i++)
    dp[1][i][1<<i]=1;

  for(int i=1;i<n;i++){
    for(int a=0;a<202;a++)
      for(int b=0;b<11;b++)
        for(int c=0;c<(1<<10);c++)
          nx[a][b][c]=M(0);

    for(int a=0;a<202;a++){
      for(int b=0;b<11;b++){
        for(int c=0;c<(1<<10);c++){
          if(dp[a][b][c].v==0) continue;
          int na=a+1;
          while((c>>(na-(a+1)))&1) na++;
          if(na>a+k) continue;

          int nc=c>>(na-a);
          for(int nb=0;nb<k;nb++){
            if((nc>>nb)&1) continue;
            if(a+1+b>=na+1+nb) continue;
            if(a+1+b+k<na+1+nb) continue;
            nx[na][nb][nc|(1<<nb)]+=dp[a][b][c];
          }
        }
      }
    }

    for(int a=0;a<202;a++)
      for(int b=0;b<11;b++)
        for(int c=0;c<(1<<10);c++)
          dp[a][b][c]=nx[a][b][c];
  }

  M ans{0};
  for(int a=0;a<202;a++){
    for(int b=0;b<11;b++){
      for(int c=0;c<(1<<10);c++){
        if(dp[a][b][c].v==0) continue;
        int na=a+1;
        while((c>>(na-(a+1)))&1) na++;
        int nc=c>>(na-a);
        if((a+1+b==2*n)&&(na==2*n+1)&&(nc==0)) ans+=dp[a][b][c];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}

