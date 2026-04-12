#include <bits/stdc++.h>
using namespace std;

const int mo=998244353,g=3;
int len,n,m,N,fac[10010],ifac[10010],A[1<<15],X[1<<15],W[1<<15],iW[1<<15],ans;
char a[10010],b[10010];

int qpow(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

void NTT(int *a,int n,int op)
{
	for (int i=0; i<n; i++)
		{
			int t=i,p=0;
			for (int j=1; j<n; j<<=1)  p<<=1,p|=(t&1),t>>=1;
			if (p<i)  swap(a[i],a[p]);
		}
	int *w=op>0?W:iW,u,v;
	for (int len=2; len<=n; len<<=1)
		for (int i=0; i<n; i+=len)
			for (int j=0; j<(len>>1); j++)
				{
					u=a[i+j],v=1LL*a[i+j+(len>>1)]*w[n/len*j]%mo;
					a[i+j]=(u+v)%mo,a[i+j+(len>>1)]=(u-v+mo)%mo;
				}
	if (op==-1)
		{
			int inv=qpow(n,mo-2);
			for (int i=0; i<n; i++)  a[i]=1LL*a[i]*inv%mo;
		}
}

void qpow(int b)
{
	A[0]=1;
	while (b)
		{
			NTT(X,N,1);
			if (b&1)
				{
					NTT(A,N,1);
					for (int i=0; i<N; i++)  A[i]=1LL*A[i]*X[i]%mo;
					NTT(A,N,-1);
					for (int i=n+1; i<N; i++)  A[i]=0;
				}
			for (int i=0; i<N; i++)  X[i]=1LL*X[i]*X[i]%mo;
			NTT(X,N,-1);
			for (int i=n+1; i<N; i++)  X[i]=0;
			b>>=1;
		}
}

void work()
{
	scanf("%s\n%s",a+1,b+1),len=strlen(a+1);
	for (int i=1; i<=len; i++)
		if ((a[i]=='1')&&(b[i]=='1'))  n++;
		else  if ((a[i]=='1')&&(b[i]=='0'))  m++;
	fac[0]=1;
	for (int i=1; i<=n+m+1; i++)  fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n+m+1]=qpow(fac[n+m+1],mo-2);
	for (int i=n+m+1; i; i--)  ifac[i-1]=1LL*ifac[i]*i%mo;
	for (N=1; N<=2*n; N<<=1);
	for (int i=0; i<=n; i++)  X[i]=ifac[i+1];
	W[0]=iW[0]=1,W[1]=qpow(g,(mo-1)/N);
	for (int i=2; i<N; i++)  W[i]=1LL*W[i-1]*W[1]%mo;
	for (int i=1; i<N; i++)  iW[i]=W[N-i];
	qpow(m);
	for (int i=0; i<=n; i++)  ans=(ans+A[i])%mo;
	ans=1LL*ans*fac[n+m]%mo*fac[m]%mo*fac[n]%mo;
	printf("%d",ans);
}

int main()
{
	work();
	return 0;
}
