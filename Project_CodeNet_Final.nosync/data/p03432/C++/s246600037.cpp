#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int mod=998244353;
const int N=(1<<14)+10;
int Pow(int x,int y) {
	int res=1;
	while(y) {
		if(y&1) res=res*(ll)x%mod;
		x=x*(ll)x%mod,y>>=1;
	}
	return res;
}
int wn[2][N];
void getwn(int l) {
	for(int i=1;i<(1<<l);i<<=1) {
		int w0=Pow(3,(mod-1)/(i<<1)),w1=Pow(3,mod-1-(mod-1)/(i<<1));
		wn[0][i]=wn[1][i]=1;
		for(int j=1;j<i;++j)
			wn[0][i+j]=wn[0][i+j-1]*(ll)w0%mod,
			wn[1][i+j]=wn[1][i+j-1]*(ll)w1%mod;
	}
}
int rev[N];
void getr(int l) { for(int i=1;i<(1<<l);++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1); }
void FFT(int *A,int len,int f) {
	for(int i=0;i<len;++i) if(rev[i]<i) swap(A[i],A[rev[i]]);
	for(int l=1;l<len;l<<=1)
		for(int i=0;i<len;i+=(l<<1))
			for(int k=0;k<l;++k) {
				int t1=A[i+k],t2=A[i+l+k]*(ll)wn[f][l+k]%mod;
				A[i+k]=(t1+t2)%mod;
				A[i+l+k]=(t1-t2+mod)%mod;
			}
	if(f==1) for(int inv=Pow(len,mod-2),i=0;i<len;++i) A[i]=A[i]*(ll)inv%mod;
}
int A[N],B[N];
int f[210][8010];
int fac[8010],inv[8010];
void getfac(int n) {
	fac[0]=1; for(int i=1;i<=n;++i) fac[i]=fac[i-1]*(ll)i%mod;
	inv[n]=Pow(fac[n],mod-2); for(int i=n;i>=1;--i) inv[i-1]=inv[i]*(ll)i%mod;
}
int C(int n,int m) { return fac[n]*(ll)inv[m]%mod*inv[n-m]%mod; }
int n,m;
int main() {
	rd(n),rd(m);
	getfac(n+2),getwn(14);
	int len=1,cnt=0; while(len<=n*2) len<<=1,cnt++; getr(cnt);
	
	for(int i=1;i<=n;++i) B[i]=inv[i+2];
	FFT(B,len,0);
	
	f[0][0]=1;
	for(int i=1;i<=m;++i) {
		for(int j=0;j<=n;++j) A[j]=f[i-1][j]*(ll)inv[j]%mod;
		for(int j=n+1;j<len;++j) A[j]=0;
		FFT(A,len,0);
		for(int j=0;j<len;++j) A[j]=A[j]*(ll)B[j]%mod;
		FFT(A,len,1);
		for(int j=0;j<=n;++j) f[i][j]=A[j]*(ll)fac[j+2]%mod;
		for(int j=0;j<=n;++j) f[i][j]=(f[i][j]+f[i-1][j]*(ll)(C(j+1,2)+1))%mod;
//		cout<<i<<':';
//		for(int j=0;j<=n;++j) printf("%d ",f[i][j]); puts("");
	}
	int ans=0;
	for(int i=0;i<=n;++i) ans=(ans+f[m][i]*(ll)C(n,i)%mod)%mod;
	printf("%d",ans);
	return 0;
}