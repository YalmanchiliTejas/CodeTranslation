#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 40009
using namespace std;

int n,m,w[2][N],pos[N],fac[N],inv[N],a[N],b[N],na[N],fa[N],fb[N];
char s1[N],s2[N];
int ksm(int x,int y){
	int z=1; for (; y; y>>=1,x=(ll)x*x%mod) if (y&1) z=(ll)z*x%mod;
	return z;
}
int pwk(int m){
	int i,n=1; for (; n<=m; n<<=1);
	int x=ksm(3,(mod-1)/n);
	for (i=w[0][0]=w[1][0]=1; i<n; i++)
		w[0][i]=w[1][n-i]=(ll)w[0][i-1]*x%mod;
	for (i=0; i<n; i++) pos[i]=pos[i>>1]>>1|((i&1)?n>>1:0);
	return n;
}
void fft(int *a,int n,int p){
	int i,j,k,l,x,y;
	for (i=0; i<n; i++) na[pos[i]]=a[i];
	for (i=0; i<n; i++) a[i]=na[i];
	for (k=1; k<n; k<<=1)
		for (i=0,x=n/k>>1; i<n; i+=k<<1)
			for (j=i,l=0; j<i+k; j++,l+=x){
				y=(ll)a[j+k]*w[p][l]%mod;
				a[j+k]=(a[j]-y+mod)%mod; a[j]=(a[j]+y)%mod;
			}
	if (p){
		x=ksm(n,mod-2);
		for (i=0; i<n; i++) a[i]=(ll)a[i]*x%mod;
	}
}
void mul(int *a,int *b,int *c,int n,int m){
	int i;
	for (i=0; i<n; i++){
		fa[i]=a[i]; fb[i]=b[i];
	}
	fft(fa,n,0); fft(fb,n,0);
	for (i=0; i<n; i++) c[i]=(ll)fa[i]*fb[i]%mod;
	fft(c,n,1);
	for (i=m+1; i<n; i++) c[i]=0;
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	int i,len=strlen(s1+1);
	for (i=1; i<=len; i++) if (s1[i]=='1')
		if (s2[i]=='1') n++; else m++;
	fac[0]=inv[0]=inv[1]=1;
	for (i=1; i<N; i++) fac[i]=(ll)fac[i-1]*i%mod;
	for (i=2; i<N; i++) inv[i]=mod-(ll)inv[mod%i]*(mod/i)%mod;
	for (i=2; i<N; i++) inv[i]=(ll)inv[i-1]*inv[i]%mod;
	for (i=0; i<=n; i++) a[i]=inv[i+1];
	b[0]=1;
	len=pwk(n<<1);
	for (i=m; i; i>>=1,mul(a,a,a,len,n)) if (i&1) mul(b,a,b,len,n);
	int ans=0;
	for (i=0; i<=n; i++) ans=(ans+b[i])%mod;
	printf("%lld\n",(ll)ans*fac[m]%mod*fac[n]%mod*fac[m+n]%mod);
	return 0;
}
