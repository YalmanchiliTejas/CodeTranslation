#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end

template<unsigned mod=1000000007>struct fp {
   int v; static unsigned get_mod(){return mod;}
   int inv() const{
      int tmp,a=v,b=mod,x=1,y=0;
      while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
      if(x<0){x+=mod;} return x;
   }
   fp():v(0){}
   fp(ll x):v(x>=0?x%mod:mod+(x%mod)){}
   fp operator-()const{return fp(-v);}
   fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return res;}
   fp& operator+=(const fp& x){if((v+=x.v)>=(int)mod)v-=mod; return *this;}
   fp& operator-=(const fp& x){if((v+=mod-x.v)>=(int)mod)v-=mod; return *this;}
   fp& operator*=(const fp& x){v=ll(v)*x.v%mod; return *this;}
   fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return *this;}
   fp operator+(const fp& x)const{return fp(*this)+=x;}
   fp operator-(const fp& x)const{return fp(*this)-=x;}
   fp operator*(const fp& x)const{return fp(*this)*=x;}
   fp operator/(const fp& x)const{return fp(*this)/=x;}
   bool operator==(const fp& x)const{return v==x.v;}
   bool operator!=(const fp& x)const{return v!=x.v;}
}; using Fp=fp<>;

int main(){
   int n; cin>>n;
   vector<int> a(n);
   Fp sum=0;
   rep(i,0,n)cin>>a[i],sum+=a[i];
   Fp res;
   rep(i,0,n)res+=(sum-a[i])*a[i],sum-=a[i];
   cout<<res.v<<endl;
   return 0;
}