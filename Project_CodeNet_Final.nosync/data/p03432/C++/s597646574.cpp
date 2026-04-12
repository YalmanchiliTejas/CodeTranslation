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
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int L=14,N=1<<L;
const int mod=998244353;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

inline int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
}

int W[N*2],*w0[L],*w1[L],R[N];
inline void DFT(int *a,int n,int f) {
	int i,o,k,t,*wn,*w,x,y;
	for (i=0;i<n;i++)
		if (R[i]>i) swap(a[i],a[R[i]]);
	for (i=1,t=0;i<n;i<<=1,t++)
		for (o=0,wn=f==1?w0[t]:w1[t];o<n;o+=i<<1)
			for (k=0,w=wn;k<i;k++,w++) {
				x=a[o+k],y=1LL*a[o+k+i]**w%mod;
				a[o+k]=(x+y)%mod;
				a[o+k+i]=(x-y+mod)%mod;
			}
}

int f[210][N],g[N],h[N];
int fac[N],inv[N];
int main()
{
	int n=gi(),m=gi(),i,j,len,t,*cur=W,LEN,G;
	for (i=fac[0]=1;i<=n+2;i++) fac[i]=1LL*fac[i-1]*i%mod;
	for (i=2,inv[0]=inv[1]=1;i<=n+2;i++) inv[i]=mod-1LL*(mod/i)*inv[mod%i]%mod;
	for (i=3;i<=n+2;i++) inv[i]=1LL*inv[i-1]*inv[i]%mod;
	
	for (len=1,t=0;len<=n*2;len<<=1,t++) {
		G=qpow(3,(mod-1)/(len<<1));w0[t]=cur;
		for (i=cur[0]=1;i<len;i++) cur[i]=1LL*cur[i-1]*G%mod;
		cur+=len;
		G=qpow(G,mod-2);w1[t]=cur;
		for (i=cur[0]=1;i<len;i++) cur[i]=1LL*cur[i-1]*G%mod;
		cur+=len;
	}
	for (i=0,t--;i<len;i++)
		R[i]=R[i>>1]>>1|(i&1)<<t;
	LEN=qpow(len,mod-2);

	f[0][0]=1;
	for (i=1;i<=n;i++) g[i]=inv[i+2];DFT(g,len,1);
	for (i=0;i<m;i++) {
		for (j=0;j<=n;j++) {
			f[i+1][j]=(1LL*(j+1)*j/2+1)%mod*f[i][j]%mod;
			f[i][j]=1LL*f[i][j]*inv[j]%mod;
		}
		DFT(f[i],len,1);
		for (j=0;j<len;j++)
			f[i][j]=1LL*f[i][j]*g[j]%mod;
		DFT(f[i],len,-1);
		for (j=0;j<=n;j++)
			f[i+1][j]=(f[i+1][j]+1LL*f[i][j]*LEN%mod*fac[j+2])%mod;
	}
	int ans=0;
	for (j=0;j<=n;j++)
		ans=(ans+1LL*fac[n]*inv[j]%mod*inv[n-j]%mod*f[m][j])%mod;
	cout<<ans<<endl;
	return 0;
}
