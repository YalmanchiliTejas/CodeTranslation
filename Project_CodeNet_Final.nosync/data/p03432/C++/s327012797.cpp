#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
using i32 = int;
using u32 = unsigned;
using u64 = unsigned long long;

struct Mod32 {
  Mod32() : n_(0) {}
  Mod32(u32 n) : n_(init(n)) {}
  static u32 modulus() { return mod; }
  static u32 init(u32 w) { return reduce(u64(w) * r2); }
  static void set_mod(u32 m) {
    mod = m;
    inv = m; for (int i = 0; i < 5; ++i) inv *= 2 - inv * m;
    r2 = -u64(m) % m;
  }
  static u32 reduce(u64 x) {
    u32 y = u32(x >> 32) - u32((u64(u32(x) * inv) * mod) >> 32);
    return i32(y) < 0 ? y + mod : y;
  }
  Mod32& operator += (Mod32 rhs) { n_ += rhs.n_ - mod; if (i32(n_) < 0) n_ += mod; return *this; }
  Mod32 operator + (Mod32 rhs) const { return Mod32(*this) += rhs; }
  Mod32& operator -= (Mod32 rhs) { n_ -= rhs.n_; if (i32(n_) < 0) n_ += mod; return *this; }
  Mod32 operator - (Mod32 rhs) const { return Mod32(*this) -= rhs; }
  Mod32& operator *= (Mod32 rhs) { n_ = reduce(u64(n_) * rhs.n_); return *this; }
  Mod32 operator * (Mod32 rhs) const { return Mod32(*this) *= rhs; }
  u32 get() const { return reduce(n_); }
  static u32 mod, inv, r2;
  u32 n_;
};
u32 Mod32::mod, Mod32::inv, Mod32::r2;
const int MOD=998244353;
Mod32 w[2][SZ],rv; int K;
inline Mod32 qp(Mod32 a,ll b)
{
    Mod32 ans=1;
    while(b)
    {
        if(b&1) ans=ans*a;
        a=a*a; b>>=1;
    }
    return ans;
}
inline void fftinit(int n)
{
    for(K=1;K<n;K<<=1);
    w[0][0]=w[0][K]=1;
    Mod32 g=qp(3,(MOD-1)/K); rv=qp(K,MOD-2);
    for(int i=1;i<K;i++) w[0][i]=w[0][i-1]*g;
    for(int i=0;i<=K;i++) w[1][i]=w[0][K-i];
}
inline void fft(Mod32* x,int v)
{
    for(int i=0,j=0;i<K;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=K>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=K;i<<=1)
        for(int l=0;l<i>>1;l++)
        {
            register Mod32 W=w[v][K/i*l],*p=x+l+(i>>1),*q=x+l,t;
            for(register int j=0;j<K;j+=i)
            	t=p[j]*W, p[j]=q[j]-t, q[j]+=t;
        }
    if(!v) return;
    for(int i=0;i<K;i++) x[i]=x[i]*rv;
}
#define SZ 666666
Mod32 f[233][8888],a[16388],b[16388],fac[SZ],rfac[SZ],coe[SZ];
int main()
{
	Mod32::set_mod(MOD); fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i>=1;--i) rfac[i-1]=rfac[i]*i;
	fftinit(16000); f[0][0]=1;
	for(int j=1;j<=8003;++j) b[j]=rfac[j+2];
	fft(b,0);
	for(int j=0;j<=8003;++j)
		coe[j]=((j+1)*(ll)j/2+1)%MOD;
	for(int i=1;i<=200;++i)
	{
		for(int k=0;k<K;++k) a[k]=0;
		for(int k=0;k<=8003;++k)
			a[k]=f[i-1][k]*rfac[k];
		fft(a,0);
		for(int k=0;k<K;++k) a[k]=a[k]*b[k];
		fft(a,1);
		for(int k=0;k<=8003;++k)
			f[i][k]=f[i-1][k]*coe[k]+a[k]*fac[k+2];
	}
	int n,m;
	cin>>n>>m;
	Mod32 ans=0;
	for(int i=0;i<=n;++i)
		ans+=f[m][i]*fac[n]*rfac[i]*rfac[n-i];
	int g=ans.get();
	printf("%d\n",int(g));
}
