//BadWaper gg
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define N 8010
#define M 210
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
const int mod=998244353;
int f[M][N],a[N<<2],b[N<<2],c[N<<2],r[N<<2],limit=1,l=0;
int n,m,t;
int fac[N],inv[N];
inline int C(int n,int m){if(n<m)return 0;return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline int ksm(int a,int b)
{
	int ans=1;
	while(b){if(b&1)ans=1LL*ans*a%mod;b>>=1;a=1LL*a*a%mod;}
	return ans;
}
inline int Z(int x){return x>=mod?x-mod:x;}
inline void NTT(int a[],int flag)
{
	for(register int i=0;i<limit;i++)if(i<r[i])swap(a[i],a[r[i]]);
	for(register int mid=1;mid<limit;mid<<=1)
	{
		int Wn=ksm(3,(mod-1)/(mid<<1));if(flag<0)Wn=ksm(Wn,mod-2);
		for(register int R=(mid<<1),j=0;j<limit;j+=R)
		{
			int w=1;
			for(register int k=0;k<mid;k++,w=1LL*w*Wn%mod)
			{
				int x=a[j+k],y=1LL*a[j+k+mid]*w%mod;
				a[j+k]=Z(x+y);a[j+k+mid]=Z(x+mod-y);
			}
		}
	}
	int inv=ksm(limit,mod-2);
	if(flag<0)for(register int i=0;i<limit;i++)a[i]=1LL*a[i]*inv%mod;
}
inline void mul(int a[],int b[],int c[],int len1,int len2)
{
	limit=1,l=0;
	while(limit<=len1+len2)limit<<=1,l++;
	for(register int i=len1+1;i<limit;i++)a[i]=0;
	for(register int i=len2+1;i<limit;i++)b[i]=0;
	for(register int i=0;i<limit;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	NTT(a,1);NTT(b,1);
	for(register int i=0;i<limit;i++)c[i]=1LL*a[i]*b[i]%mod;
	NTT(c,-1);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();t=max(n,m);
	fac[0]=1;
	for(register int i=1;i<N;i++)fac[i]=1LL*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(register int i=2;i<N;i++)inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	for(register int i=2;i<N;i++)inv[i]=1LL*inv[i]*inv[i-1]%mod;
	for(register int i=0;i<=n;i++)f[m][i]=C(n,i);
	for(register int i=m-1;i>=0;i--)
	{
		for(register int j=0;j<=n;j++)f[i][j]=1LL*f[i+1][j]*(C(j+1,2)+1)%mod;
		for(register int j=1;j<=n;j++)a[n-j+1]=1LL*f[i+1][j]*fac[j+2]%mod;
		for(register int j=1;j<=n;j++)b[j]=inv[j+2];
//		for(register int j=0;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
//		for(register int j=0;j<=n;j++)cout<<b[j]<<" ";cout<<endl;
		mul(a,b,c,n,n);
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));
//		for(register int j=0;j<limit;j++)cout<<c[j]<<" ";cout<<endl;
		for(register int j=0;j<=n;j++)f[i][j]=Z(f[i][j]+1LL*inv[j]*c[n-j+1]%mod);
		memset(c,0,sizeof(c));
//		for(register int j=0;j<=n;j++)cout<<f[i][j]<<" ";cout<<endl;cout<<endl;
	}
	printf("%d\n",f[0][0]);
	return 0;
}
/*
3 2
*/