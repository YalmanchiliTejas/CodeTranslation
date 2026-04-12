#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vi poly;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int mod=998244353;
namespace Poly{
	const int N=(1<<20)+5,g=3;
	inline int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	void dft(poly &A,int n){
		static ull W[N<<1],*H[30],*las=W,mx=0;
		for(;mx<n;mx++){
			H[mx]=las;ull w=1,wn=power(g,(mod-1)>>(mx+1));
			REP(i,1<<mx)*las++=w,w=w*wn%mod;
		}
		static ull a[N];A.resize(1<<n);
		for(int i=0,j=0;i<(1<<n);++i){
			a[i]=A[j];
			for(int k=1<<(n-1);(j^=k)<k;k>>=1);
		}
		for(int k=0,d=1;k<n;k++,d<<=1)
			for(int i=0;i<(1<<n);i+=d<<1){
				ull *l=a+i,*r=a+i+d,*w=H[k],t;
				for(int j=0;j<d;++j,++l,++r){
					t=(*w++)*(*r)%mod;
					*r=*l+mod-t,*l+=t;
				}
			}
		REP(i,1<<n)A[i]=a[i]%mod;
	}
	void idft(poly &a,int n){
		a.resize(1<<n);
		reverse(a.begin()+1,a.end());
		dft(a,n);
		int inv=power(1<<n,mod-2);
		REP(i,1<<n)a[i]=(ll)a[i]*inv%mod;
	}
	poly mul(poly a,poly b){
		int aim=(a.size()+b.size()),n=1;
		while((1<<n)<=aim)n++;
		dft(a,n),dft(b,n);
		REP(i,1<<n)a[i]=(ll)a[i]*b[i]%mod;
		return idft(a,n),a.resize(aim),a;
	}
}

const int N=205,M=8005;
int fac[M],rev[M],f[N][M],n,m;
void init(int n){
	fac[0]=1;
	rep(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	rev[n]=Poly::power(fac[n],mod-2);
	per(i,n,1)rev[i-1]=(ll)rev[i]*i%mod;
}

poly A,B,C;

int main(){
	read(m),read(n),init(m+2);
	rep(i,0,m)f[n+1][i]=(ll)fac[m]*rev[i]%mod*rev[m-i]%mod;
	A.resize(m+1),B.resize(m+1);
	per(i,n,1){
		rep(j,1,m){
			A[j]=(ll)fac[j+2]*f[i+1][j]%mod;
			B[m-j]=rev[j+2];
		}
		C=Poly::mul(A,B);
		rep(j,0,m)
			f[i][j]=((ll)C[m+j]*rev[j]
				   +((ll)j*(j+1)/2+1)%mod*f[i+1][j])%mod;
	}
	printf("%d\n",f[1][0]);
	return 0;
}