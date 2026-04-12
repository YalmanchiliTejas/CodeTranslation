#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(long long aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar('0'+aa%10);
	return;
}
const int mod=998244353;
int n,m,len;
int fac[10005],ny[10005];
int f[10005][10005];
char a[10005],b[10005];
int ksm(int aa,int bb)
{
	int now=1;
	while(bb)
	{
		if(bb&1) now=1ll*now*aa%mod;
		aa=1ll*aa*aa%mod;bb>>=1;
	}
	return now;
}
int C(int aa,int bb)
{
	return 1ll*fac[bb]*ny[aa]%mod*ny[bb-aa]%mod;
}
int main()
{
	cin>>a>>b;
	len=strlen(a);fac[0]=1;
	for(int i=1;i<=len;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ny[len]=ksm(fac[len],mod-2);
	for(int i=len;i;i--) ny[i-1]=1ll*ny[i]*i%mod;
	for(int i=0;i<len;++i) 
	if(a[i]=='1'&&b[i]=='1') n++;
	else if(a[i]=='1') m++;
	f[0][0]=1;
	for(int i=0;i<=n;++i)
	for(int j=0;j<=m;++j)
	{
		if(j) f[i][j]=(f[i][j]+1ll*f[i][j-1]*j*j%mod)%mod;
		if(i) f[i][j]=(f[i][j]+1ll*f[i-1][j]*i*j%mod)%mod;
	}
	for(int i=0;i<n;++i) 
	f[n][m]=(f[n][m]+1ll*f[i][m]*fac[n-i]%mod*fac[n-i]%mod*C(n-i,n+m)%mod*C(n-i,n)%mod)%mod;
	write(f[n][m]);
	return 0;
}