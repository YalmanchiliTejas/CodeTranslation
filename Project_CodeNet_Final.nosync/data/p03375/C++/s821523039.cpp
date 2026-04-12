#include<algorithm>
#include<cstdio>
using namespace std;
int n,P,sl,fh,res,ans,pw1[3010],pw2[3010][3010],C[3010][3010],S[3010][3010];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int _pow(int k,int i)
{
	int t=1;
	for(;i;i>>=1,k=1ll*k*k%P)
		if(i&1)
			t=1ll*t*k%P;
	return t;
}
int main()
{
	n=rd();P=rd();pw1[0]=pw2[0][1]=1;
	for(int i=1;i<=n;++i) pw2[i][1]=2ll*pw2[i-1][1]%P,pw1[i]=2ll*pw1[i-1]%(P-1);
	for(int i=0;i<=n;++i) pw1[i]=_pow(2,pw1[i]);
	for(int i=0;i<=n;++i) pw2[i][0]=pw2[0][i]=C[i][0]=1;
	S[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=P) C[i][j]-=P;
			S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%P;
		}
		for(int j=2;j<=n-i;++j) pw2[i][j]=1ll*pw2[i][1]*pw2[i][j-1]%P;
	}
	for(int i=1;i<=n+1;++i) S[n+1][i]=(S[n][i-1]+1ll*i*S[n][i])%P;
	for(int x=1,i=0;i<=n;++i,x=-x)
	{
		res=0;
		for(int j=0;j<=i;++j) res=(res+1ll*S[i+1][j+1]*pw2[n-i][j])%P;
		ans=(ans+1ll*x*res*C[n][i]%P*pw1[n-i])%P;
	}
	if(ans<0) ans+=P;
	printf("%d\n",ans);
	return 0;
}