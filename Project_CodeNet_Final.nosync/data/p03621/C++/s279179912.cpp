#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const long long md=998244353;
char s1[10010],s2[10010];
long long dp1[10010],dp2[10010];
long long fac[10010],inv[10010];
long long powd(long long x,long long y)
{
	long long res=1;
	while(y){
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
}
long long C(int n,int m){
	return fac[n]*inv[m]%md*inv[n-m]%md;
}
long long cnt(int s,int t){
	return fac[t]*fac[t]%md*C(s+t,t)%md;
}
int Max(int x,int y){
	return x>y?x:y;
}
int main(){
//	freopen("E.in","r",stdin);
	int n;
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%md;
	inv[n]=powd(fac[n],md-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%md;
	int num=0,k=0;
	for(int i=1;i<=n;i++)
	{
		if(s1[i]=='1')
			num++;
		if(s2[i]=='1')
			num++;
		if(s1[i]=='1'&&s2[i]=='1')
			k++;
	}
	num=num/2;
	k=num-k;
	if(k==0){
		printf("%lld\n",fac[num]*fac[num]%md);
		return 0;
	}
	long long *p=dp1,*q=dp2;
	dp1[0]=1;
	long long ans=0;
	for(int i=1;i<=num;i++)
	{
		for(int j=0;j<=i&&j<=k;j++)
			q[j]=0;
		for(int j=1;j<=i&&j<=k;j++)
			q[j]=(p[j-1]*(k-j+1)%md*(k-j+1)+p[j]*j%md*Max(num-k-i+j+1,0))%md;
		ans=(ans+q[k]*cnt(i,num-i))%md;
		swap(p,q);
	}
	printf("%lld\n",ans);
	return 0;
}
