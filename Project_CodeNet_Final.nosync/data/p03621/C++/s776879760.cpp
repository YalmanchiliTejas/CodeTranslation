#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10010
#define ll long long
#define P 998244353
using namespace std;
int n,m;
ll q[N],ni[N],nq[N];
int f[N][N];
char a[N],b[N];
ll C(int n,int m)
{
	return q[n]*nq[m]%P*nq[n-m]%P;
}
int main()
{
	q[0]=ni[1]=nq[0]=1;
	for(int i=1;i<N;i++) q[i]=q[i-1]*i%P;
	for(int i=2;i<N;i++) ni[i]=(P-P/i)*ni[P%i]%P;
	for(int i=1;i<N;i++) nq[i]=nq[i-1]*ni[i]%P;
	scanf("%s%s",a,b);
	for(int i=0;a[i];i++)
	if(a[i]=='1')
	{
		if(b[i]=='1') n++;
		else m++;
	}
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	if(i||j)
	{
		ll o=0;
		if(j) o+=(ll)j*j*f[i][j-1];
		if(i) o+=(ll)i*j*f[i-1][j];
		f[i][j]=o%P;
	}
	ll ans=0;
	for(int i=0;i<=n;i++) ans+=f[i][m]*C(n,i)%P*C(n+m,i+m)%P*q[n-i]%P*q[n-i]%P;
	ans%=P;
	cout<<ans;
}