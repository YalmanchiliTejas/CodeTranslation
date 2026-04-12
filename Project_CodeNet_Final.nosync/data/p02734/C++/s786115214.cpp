#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//end

template<unsigned mod=998244353>struct mint {
   unsigned val;
   static unsigned get_mod(){return mod;}
   unsigned inv() const{
      int tmp,a=val,b=mod,x=1,y=0;
      while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
      if(x<0)x+=mod; return x;
   }
   mint():val(0){}
   mint(ll x):val(x>=0?x%mod:mod+(x%mod)){}
   mint pow(ll t){mint res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
   mint& operator+=(const mint& x){if((val+=x.val)>=mod)val-=mod;return *this;}
   mint& operator-=(const mint& x){if((val+=mod-x.val)>=mod)val-=mod; return *this;}
   mint& operator*=(const mint& x){val=ll(val)*x.val%mod; return *this;}
   mint& operator/=(const mint& x){val=ll(val)*x.inv()%mod; return *this;}
   mint operator+(const mint& x)const{return mint(*this)+=x;}
   mint operator-(const mint& x)const{return mint(*this)-=x;}
   mint operator*(const mint& x)const{return mint(*this)*=x;}
   mint operator/(const mint& x)const{return mint(*this)/=x;}
   bool operator==(const mint& x)const{return val==x.val;}
   bool operator!=(const mint& x)const{return val!=x.val;}
};
template<unsigned mod=998244353>struct factorial {
   using Mint=mint<mod>;
   vector<Mint> Fact, Finv;
public:
   factorial(int maxx){
      Fact.resize(maxx+1),Finv.resize(maxx+1); Fact[0]=Mint(1); rep(i,0,maxx)Fact[i+1]=Fact[i]*(i+1);
      Finv[maxx]=Mint(1)/Fact[maxx]; rrep(i,maxx,0)Finv[i-1]=Finv[i]*i;
   }
   Mint fact(int n,bool inv=0){if(inv)return Finv[n];else return Fact[n];}
   Mint nPr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[n-r];}
   Mint nCr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[r]*Finv[n-r];}
};
using Mint=mint<>;

Mint dp[3010][3010],sum[3010][3010];

int main(){
   int n,k; scanf("%d%d",&n,&k);
   vector<int> a(n); rep(i,0,n)scanf("%d",&a[i]);
   rep(i,0,n+1)dp[i][0]=sum[i][0]=1;
   rep(i,0,n){
      rep(j,0,k-a[i]+1)if(sum[i][j].val){
         if(j==0)dp[i+1][j+a[i]]+=sum[i][j]*(i+1);
         else dp[i+1][j+a[i]]+=sum[i][j];
      }
      rep(j,1,k+1)sum[i+1][j]=sum[i][j]+dp[i+1][j];
   }
   Mint res=0;
   rrep(i,n-1,-1)res+=dp[i+1][k]*(n-i);
   printf("%d\n",res.val);
   return 0;
}