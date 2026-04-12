#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int N=5e4;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
char a[N],b[N];
int f[N],g[N],R[N];
int inv[N];
int INV;
const int mod=998244353;
int w0[20][N],w1[20][N];
inline int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
}
inline void DFT(int *a,int n,int f) {
	int i,o,k,x,y,t,*w,*wn;
	for (i=0;i<n;i++) if (R[i]<i) swap(a[i],a[R[i]]);
	for (i=1,t=0;i<n;i<<=1,t++)
		for (o=0,wn=f==1?w0[t]:w1[t];o<n;o+=i<<1)
			for (k=0,w=wn;k<i;k++,w++) {
				x=a[o+k],y=1LL*a[o+k+i]**w%mod;
				a[o+k]=(x+y)%mod;
				a[o+k+i]=(x-y)%mod;
			}
}
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	int n=strlen(a+1),i,k,e=0,m=0,len,L=0,G,t;
	for (i=2,inv[0]=inv[1]=1;i<=n;i++) inv[i]=mod-1LL*(mod/i)*inv[mod%i]%mod;
	for (i=3;i<=n;i++) inv[i]=1LL*inv[i]*inv[i-1]%mod;
	for (i=1;i<=n;i++) if (a[i]=='1') b[i]=='1'?m++:e++;

	for (len=1;len<=(m<<1);len<<=1,L++) {
		G=qpow(3,(mod-1)/(len<<1));
		for (i=w0[L][0]=1;i<=len;i++) w0[L][i]=1LL*w0[L][i-1]*G%mod;
		w1[L][len]=w0[L][len];
		for (i=len;i;i--) w1[L][i-1]=1LL*w1[L][i]*G%mod;
	}
	for (i=0,L--;i<len;i++) R[i]=R[i>>1]>>1|(i&1)<<L;
	INV=qpow(len,mod-2);

	for (i=0;i<=m;i++) f[i]=!i,g[i]=inv[i+1];
	for (t=e;t;t>>=1) {
		for (i=m+1;i<len;i++) g[i]=0;
		DFT(g,len,1);
		if (t&1) {
			for (i=m+1;i<len;i++) f[i]=0;
			DFT(f,len,1);
			for (i=0;i<len;i++) f[i]=1LL*f[i]*g[i]%mod;
			DFT(f,len,-1);
			for (i=0;i<=m;i++) f[i]=1LL*f[i]*INV%mod;
		}
		for (i=0;i<len;i++) g[i]=1LL*g[i]*g[i]%mod;
		DFT(g,len,-1);
		for (i=0;i<=m;i++) g[i]=1LL*g[i]*INV%mod;
	}
	for (i=k=0;i<=m;i++) (k+=f[i])%=mod;

	for (i=m+e;i;i--) k=1LL*k*i%mod;
	for (i=m;i;i--) k=1LL*k*i%mod;
	for (i=e;i;i--) k=1LL*k*i%mod;
	printf("%d\n",(k+mod)%mod);
	return 0;
}
