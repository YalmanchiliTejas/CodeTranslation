#include<bits/stdc++.h>
using namespace std;

const int N=10005,P=998244353,G=3;
int n,e,m,f[N],rf[N];
char a[N],b[N];

int pw(int a,int x)
{
	int ans=1;
	for(;x;x>>=1,a=1ll*a*a%P)
		if(x&1)ans=1ll*ans*a%P;
	return ans;
}

void dft(int *a,int n,int inv)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i>j)swap(a[i],a[j]);
		for(int k=n>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=n;i<<=1)
	{
		int m=i>>1,wn=pw(G,P-1+inv*(P-1)/i);
		for(int *p=a;p<a+n;p+=i)
			for(int j=0,w=1;j<m;j++,w=1ll*w*wn%P)
			{
				int t=1ll*w*p[m+j]%P;
				p[m+j]=(p[j]-t)%P;
				p[j]=(p[j]+t)%P;
			}
	}
	if(inv==-1)
		for(int i=0,t=pw(n,P-2);i<n;i++)a[i]=1ll*a[i]*t%P;
}

typedef vector<int> poly;
poly operator*(const poly&a,const poly&b)
{
	poly c;
	static int ta[N<<2],tb[N<<2];
	copy(a.begin(),a.end(),ta);
	copy(b.begin(),b.end(),tb);
	int l=1;
	for(;l<=m<<1;l<<=1);
	dft(ta,l,1),dft(tb,l,1);
	for(int i=0;i<l;i++)ta[i]=1ll*ta[i]*tb[i]%P;
	dft(ta,l,-1);
	for(int i=0;i<=m;i++)c.push_back(ta[i]);
	for(int i=0;i<l;i++)ta[i]=tb[i]=0;
	return c;
}
poly power(poly a,int n)
{
	poly ans(m+1);ans[0]=1;
	for(;n;n>>=1,a=a*a)
		if(n&1)ans=ans*a;
	return ans;
}

int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		e+=a[i]=='1'&&b[i]=='0';
		m+=a[i]=='1'&&b[i]=='1';
	}
	for(int i=f[0]=1;i<=n;i++)f[i]=1ll*f[i-1]*i%P;
	rf[n]=pw(f[n],P-2);
	for(int i=n;i;i--)rf[i-1]=1ll*rf[i]*i%P;
	poly a;
	for(int i=0;i<=m;i++)
		a.push_back(rf[i+1]);
	a=power(a,e);
	int ans=0;
	for(int i=0;i<=m;i++)ans=(ans+a[i])%P;
	ans=1ll*ans*f[e]%P*f[m]%P*f[e+m]%P;
	printf("%d\n",(ans+P)%P);
	return 0;
}
