#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
const int maxn = 40010;
const int mod = 998244353;
int add(int x,int y) { x+=y; return x>=mod?x-mod:x; }
int sub(int x,int y) { x-=y; return x<0?x+mod:x; }
int mul(int x,int y) { return 1ll*x*y%mod; }
int ksm(int a,int b) {
	int ans=1; for(;b;b>>=1,a=mul(a,a)) if(b&1) ans=mul(ans,a);
	return ans;
}
int n,m;
//int dp[maxn][maxn];
int fac[maxn],finv[maxn];
int getc(int x,int y) {
	if(x<y) return 0;
	return mul(fac[x],mul(finv[y],finv[x-y]));
}
/*
int main() {
	scanf("%d%d",&n,&m);
	fac[0]=1; for(int i=1;i<=n+5;i++) fac[i]=mul(fac[i-1],i);
	finv[n+5]=ksm(fac[n+5],mod-2); for(int i=n+4;i>=0;i--) finv[i]=mul(finv[i+1],i+1);
	for(int i=0;i<=n;i++) dp[i][1] = 1;
	for(int j=2;j<=m;j++) {
		for(int i=0;i<=n;i++) {
			dp[i][j] = mul(add(getc(i+1,2),1),dp[i][j-1]);
			for(int k=0;k<=i-1;k++) {
				dp[i][j] = add(dp[i][j], mul(dp[k][j-1],getc(i+2,i-k+2)) );
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=n;i++) ans = add(ans,mul(getc(n,i),dp[i][m]) );
	printf("%d",ans);
}
*/
const int g = 3;
void ntt(int *a,int s,int dft) {
	for(int i=0,j=0;i<s;i++) {
		if(i<j) swap(a[i],a[j]);
		for(int k=(s>>1);(j^=k)<k;k>>=1);
	}
	for(int st=1;st<s;st<<=1) {
		int dwg = (dft==1) ? ksm(g,(mod-1)/(st<<1) ) : ksm(g,mod-1-(mod-1)/(st<<1) );
		for(int i=0;i<s;i+=(st<<1)) {
			int ng = 1;
			for(int j=i;j<i+st;j++) {
				int x = a[j]; int y = mul(ng,a[j+st]);
				ng = mul(ng,dwg);
				a[j] = add(x,y); a[j+st] = sub(x,y);
			}
		}
	}
	if(dft==1) return;
	int invs = ksm(s,mod-2);
	for(int i=0;i<s;i++) a[i] = mul(a[i],invs);
}
int ta[maxn],tb[maxn];
void MUL(int *a,int *b,int *o,int deg) {
	for(int i=0;i<deg;i++) ta[i]=a[i],tb[i]=b[i];
	ntt(ta,deg,1); ntt(tb,deg,1);
	for(int i=0;i<deg;i++) ta[i]=mul(ta[i],tb[i]);
	ntt(ta,deg,-1);
	for(int i=0;i<deg;i++) o[i]=ta[i];
}
int f[maxn],bc[maxn],z[maxn],tmp[maxn];
int main() {
	scanf("%d%d",&n,&m);
	fac[0]=1; for(int i=1;i<=n+5;i++) fac[i]=mul(fac[i-1],i);
	finv[n+5]=ksm(fac[n+5],mod-2); for(int i=n+4;i>=0;i--) finv[i]=mul(finv[i+1],i+1);
	for(int i=0;i<=n;i++) f[i] = 1;
	int deg = 1; for(;deg<=2*n;deg<<=1);
	for(int i=0;i<=n;i++) z[i]=finv[i+3];
	for(int orz=2;orz<=m;orz++) {
		for(int i=0;i<=n;i++) bc[i]=f[i],f[i]=mul(f[i],finv[i]);
		for(int i=n+1;i<deg;i++) f[i]=0;
		MUL(z,f,tmp,deg);
		for(int i=1;i<=n;i++) f[i]=add(mul(tmp[i-1],fac[i+2]),mul(bc[i],add(getc(i+1,2),1)));
		f[0]=1; for(int i=n+1;i<deg;i++) f[i]=0;
	}
	int ans = 0;
	for(int i=0;i<=n;i++) ans = add(ans,mul(getc(n,i),f[i]) );
	printf("%d",ans);
}