#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int c[N][N],f[N][N],n,Mod,ans;
#define mul(x,y) (1ll*(x)*(y)%Mod)
inline int add(int x, int y)
{	return (x+y>=Mod?x+y-Mod:x+y);
}
inline int po(int x, int y, int M=Mod)
{
	int r=1;
	for(;y;y>>=1,x=1ll*x*x%M) if(y&1) r=1ll*r*x%M;
	return r;
}
int main()
{
	scanf("%d%d",&n,&Mod);
	for(int i=0;i<=n;++i) f[i][0]=c[i][0]=f[i][i]=c[i][i]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
		{
			c[i][j]=add(c[i-1][j],c[i-1][j-1]);
			f[i][j]=add(f[i-1][j-1],mul(f[i-1][j],j+1));
		}
	for(int i=0;i<=n;++i)
	{
		int tmp=mul(c[n][i],po(2,po(2,n-i,Mod-1))),res=0,bs=po(2,n-i);
		if(i&1) tmp=Mod-tmp;
		for(int j=0,k=1;j<=i;++j,k=mul(k,bs))
			res=add(res,mul(f[i][j],k));
		ans=add(ans,mul(tmp,res));
	}
	printf("%d\n",ans);
}