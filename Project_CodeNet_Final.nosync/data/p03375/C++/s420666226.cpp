#include<iostream>
#include<cstdio>
using namespace std;
int n,p,C[3030][3030],S[3030][3030];
long long ksm(long long x,int t,int P)
{
	long long res=1;
	for(;t;t>>=1,x=x*x%P) if(t&1) res=res*x%P;
	return res;
}
void init()
{
	S[0][0]=1;
	for(int i=1;i<=n+1;i++)
	for(int j=1;j<=i;j++)
	S[i][j]=(1LL*j*S[i-1][j]+S[i-1][j-1])%p;
	for(int i=0;i<=n;i++) C[i][i]=C[i][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
}
int main()
{
	scanf("%d%d",&n,&p);
	init();
	int ans=0;
	for(int i=0,fl=1;i<=n;i++,fl=p-fl)
	{
		int sum=0,fc=ksm(2,n-i,p),mul=1;
		for(int j=0;j<=i;j++,mul=1LL*mul*fc%p)
		(sum+=1LL*S[i+1][j+1]*mul%p)%=p;
		(ans+=1LL*fl*sum%p*C[n][i]%p*ksm(2,ksm(2,n-i,p-1),p)%p)%=p;
	}
	printf("%d\n",ans);
	return 0;
}
	