#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int mo=998244353;
const int maxn=32768;

int len,n,m,fac[maxn],ifac[maxn];
char t1[maxn],t2[maxn];
int f[maxn],F[maxn];
int A[maxn],B[maxn],C[maxn];
int N,step,rev[maxn],wn[maxn];

int power(int x,int k)
{
	int res=1;
	while (k)
	{
		if (k&1) res=(LL)res*x%mo;
		x=(LL)x*x%mo;
		k>>=1;
	}
	return res;
}

void fft(int a[],int flag)
{
	int i,j,k;
	for (i=0;i<N;i++)
		if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (k=1;k<N;k<<=1)
	{
		int p=N+flag*N/(k<<1);
		for (i=0;i<N;i+=k<<1)
		{
			for (j=0;j<k;j++)
			{
				int x=a[i+j];
				int y=(LL)a[i+j+k]*wn[(LL)p*j%N]%mo;
				a[i+j]=(x+y)%mo;
				a[i+j+k]=(x+mo-y)%mo;
			}
		}
	}
	if (flag==-1)
	{
		int invN=power(N,mo-2);
		for (i=0;i<N;i++)
			a[i]=(LL)a[i]*invN%mo;
	}
}

void multi(int a[],int b[])
{
	int i;
	memcpy(A,a,sizeof(A));
	memcpy(B,b,sizeof(B));
	fft(A,+1);
	fft(B,+1);
	for (i=0;i<N;i++)
		C[i]=(LL)A[i]*B[i]%mo;
	fft(C,-1);
	for (i=n+1;i<N;i++) C[i]=0;
	memcpy(a,C,sizeof(C));
}

void solve()
{
	int i,w;
	for (N=1,step=0;N<=n<<1;N<<=1,step++);
	for (i=1;i<N;i++)
		rev[i]=rev[i>>1]>>1|(i&1)<<(step-1);
	w=power(5,(mo-1)/N);
	wn[0]=1;
	for (i=1;i<N;i++)
		wn[i]=(LL)wn[i-1]*w%mo;
	for (i=0;i<=n;i++)
		f[i]=ifac[i+1];
	F[0]=1;
	int k=m;
	while (k)
	{
		if (k&1) multi(F,f);
		multi(f,f);
		k>>=1;
	}
	int Ans=0;
	for (i=0;i<=n;i++)
		(Ans+=F[i])%=mo;
	Ans=(LL)Ans*fac[n]%mo;
	Ans=(LL)Ans*fac[m]%mo;
	Ans=(LL)Ans*fac[n+m]%mo;
	printf("%d\n",Ans);
}

int main()
{
#ifdef h10
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int i;
	fac[0]=1;
	for (i=1;i<=30000;i++)
		fac[i]=(LL)fac[i-1]*i%mo;
	ifac[30000]=power(fac[30000],mo-2);
	for (i=30000;i>=1;i--)
		ifac[i-1]=(LL)ifac[i]*i%mo;
	scanf("%s",t1+1);
	scanf("%s",t2+1);
	len=strlen(t1+1);
	for (i=1;i<=len;i++)
		if (t1[i]=='1') t2[i]=='1'?n++:m++;
	solve();
}
