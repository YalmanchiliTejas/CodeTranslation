#include<bits/stdc++.h>
using namespace std;

const int N=20010,mod=998244353;
int m,n,jc[N],inv[N],f[210][8010],w[16387],p[16387];
vector<int> A,B;

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

void dft(vector<int> &A,int fl)
{
	int n=16384;
	for (int i=0; i<n; i++)
		if (p[i]<i) swap(A[p[i]],A[i]);
	for (int i=1; i<n; i<<=1)
		for (int j=0; j<n; j+=(i<<1))
			for (int k=0; k<i; k++)
			{
				int t1=A[j+k],t2=1ll*A[i+j+k]*w[i+k]%mod;
				A[j+k]=(t1+t2>=mod?t1+t2-mod:t1+t2);
				A[i+j+k]=(t1<t2?t1-t2+mod:t1-t2);
			}
	if (fl==-1)
	{
		int inv=quickmi(n,mod-2);
		for (int i=0; i<n; i++) A[i]=1ll*A[i]*inv%mod;
		for (int i=1; i<(n>>1); i++) swap(A[i],A[n-i]);
	}
}

int main()
{
	jc[0]=1;
	for (int i=1; i<N; i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[N-1]=quickmi(jc[N-1],mod-2);
	for (int i=N-1; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
	for (int i=0; i<14; i++)
	{
		w[1<<i]=1; int wn=quickmi(3,(mod-1)>>(i+1));
		for (int j=(1<<i)+1; j<(1<<i+1); j++) w[j]=1ll*w[j-1]*wn%mod;
	}
	p[0]=0;
	for (int i=1; i<16384; i++) p[i]=(p[i>>1]>>1)|((i&1)?8192:0);
	scanf("%d%d",&n,&m),f[0][0]=1,B.resize(16384);
	for (int j=1; j<=n; j++) B[j]=inv[j+2];
	dft(B,1),A.resize(16384);
	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<=n; j++) A[j]=1ll*f[i-1][j]*inv[j]%mod;
		for (int j=n+1; j<16384; j++) A[j]=0; dft(A,1);
		for (int j=0; j<16384; j++) A[j]=1ll*A[j]*B[j]%mod; dft(A,-1);
		for (int j=0; j<=n; j++) f[i][j]=1ll*A[j]*jc[j+2]%mod;
		for (int j=0; j<=n; j++) f[i][j]=(f[i][j]+f[i-1][j]*((1ll*j*(j+1)/2+1)%mod))%mod;
	}
	int ans=0;
	for (int j=0; j<=n; j++) ans=(ans+1ll*f[m][j]*jc[n]%mod*inv[j]%mod*inv[n-j])%mod;
	return printf("%d\n",ans),0;
}