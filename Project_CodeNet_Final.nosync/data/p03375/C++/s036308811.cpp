#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define N 5002
int n,p,f[N],inv[N],finv[N],S[N][N],bin[N],bn[N];
inline int C(int nn,int mm)
{
	if(nn<mm)return 0;
	if(nn==mm||mm==0)return 1;
	return 1ll*f[nn]*finv[mm]%p*finv[nn-mm]%p;
}
int main()
{
	scanf("%d%d",&n,&p);
	f[1]=inv[1]=finv[1]=1;
	for(int i=2;i<=n+1;i++)
	{
		inv[i]=1ll*(p-p/i)*inv[p%i]%p;
		f[i]=1ll*f[i-1]*i%p;
		finv[i]=1ll*finv[i-1]*inv[i]%p;
	}
	S[0][0]=1;
	for(int i=1;i<=n+1;i++)for(int j=1;j<=n+1;j++)S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j]%p)%p;
	bin[0]=1;bn[0]=2;
	for(int i=1;i<=n+1;i++)bin[i]=2ll*bin[i-1]%p,bn[i]=1ll*bn[i-1]*bn[i-1]%p;
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int te=0,tb=1;
		for(int j=0;j<=i;j++)
		{
			te=(te+1ll*S[i+1][j+1]*tb%p)%p;
			tb=1ll*tb*bin[n-i]%p;
		}
		te=1ll*te*C(n,i)%p*bn[n-i]%p;
		if(i&1)ans=(ans-te+p)%p;
		else ans=(ans+te)%p;
	}
	printf("%d\n",ans);
}
