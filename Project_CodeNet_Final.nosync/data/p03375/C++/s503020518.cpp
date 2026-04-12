#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,i,j,mod,g[3005][3005],f[3005],ans,c[3005][3005];
long long qp(long long x,long long y,long long mod)
{
	if (y==0) return 1;
	if (y==1) return x;
	long long z=qp(x,y/2,mod);
	z=z*z%mod;
	if (y&1) z=z*x%mod;
	return z;
}
int main()
{
	cin>>n>>mod;
	c[0][0]=1;
	for (i=1;i<=n;i++)
	{
		c[i][0]=1;
		for (j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for (i=0;i<=n;i++)
	{
		g[i][0]=1;
		for (j=1;j<=i;j++) g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1))%mod;
	}
	for (i=0;i<=n;i++)
	{
		long long x=1,y=qp(2,n-i,mod);
		for (j=0;j<=i;j++)
		{
			(f[i]+=g[i][j]*x)%=mod;
			x=(x*y)%mod;
		}
		f[i]=f[i]*c[n][i]%mod*qp(2,qp(2,n-i,mod-1),mod)%mod;
	}
	for (i=0;i<=n;i++)
	{
		if (i&1) ans-=f[i]; else ans+=f[i];
		ans%=mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}