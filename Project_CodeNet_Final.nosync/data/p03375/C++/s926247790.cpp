#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int n,mod;
LL ans;
const int N=3010;
LL C[N][N],S[N][N];
LL ksm(LL a,LL b,LL mod)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)res=res*a%mod;
	return res;
}
void YYCH()
{
	C[0][0]=S[0][0]=1;
	for(int i=1;i<=n+1;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			S[i][j]=(S[i-1][j-1]+S[i-1][j]*j)%mod;
		}
	}
}
int main()
{
	cin>>n>>mod;YYCH();
	for(int i=0;i<=n;++i)
	{
		LL _2=ksm(2,n-i,mod),mul=(LL)(i&1?mod-1:1)*C[n][i]%mod*ksm(2,ksm(2,n-i,mod-1),mod)%mod,res=0,_2j=1;
		for(int j=0;j<=i;++j)
		{
			(res+=S[i+1][j+1]*_2j)%=mod;
			_2j=_2j*_2%mod;
		}
		(ans+=res*mul)%=mod;
	}
	cout<<ans;
	return 0;
}