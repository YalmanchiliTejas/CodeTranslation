#include<cstdio>
using namespace std;
#define N 3050
int n,p,c[N][N],s[N][N];
int pw(int a,int b,int p){int as=1;while(b){if(b&1)as=1ll*as*a%p;a=1ll*a*a%p;b>>=1;}return as;}
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=0;i<=n;i++)c[i][i]=c[i][0]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++)
	c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	s[1][1]=1;s[0][0]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<=i;j++)
	s[i][j]=(1ll*j*s[i-1][j]+s[i-1][j-1])%p;
	int as=0;
	for(int i=0;i<=n;i++)
	{
		int tp=1ll*(i&1?p-1:1)*c[n][i]%p*pw(2,pw(2,n-i,p-1),p)%p;
		int s1=1,s2=pw(2,n-i,p);
		for(int k=0;k<=i;k++)
		as=(as+1ll*tp*(s[i][k]+1ll*s[i][k+1]*(k+1)%p)%p*s1)%p,s1=1ll*s1*s2%p;
	}
	printf("%d\n",as);
}