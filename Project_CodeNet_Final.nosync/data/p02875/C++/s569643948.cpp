#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
const int N=1e7+7,mo=998244353;
inline int fk(int x) { return x>=mo ? x-mo : x; }
int n,fac[N],facinv[N];
int ksm(int x,int y)
{
	int res=1;
	while(y) { if(y&1) res=1ll*res*x%mo; x=1ll*x*x%mo; y>>=1; }
	return res;
}
inline int C(int x,int y) { return 1ll*fac[x]*facinv[y]%mo*facinv[x-y]%mo; }
int main()
{
	n=read();
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mo;
	facinv[n]=ksm(fac[n],mo-2);
	for(int i=n-1;i>=0;i--) facinv[i]=1ll*facinv[i+1]*(i+1)%mo;
	int ans=ksm(3,n);
	for(int k=n/2+1;k<=n;k++)
		ans=fk(ans-2ll*C(n,k)*ksm(2,n-k)%mo+mo);
	printf("%d\n",ans);
	return 0;
}