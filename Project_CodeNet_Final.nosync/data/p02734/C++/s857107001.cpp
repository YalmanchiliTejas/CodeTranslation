#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
inline LL read()
{
	LL kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
const int mod=998244353;
LL a[1000222],n,m,dp[1000222];
LL asd=0;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)
	{
		dp[0]++;
		for(int j=m;j>=a[i];--j)dp[j]=(dp[j]+dp[j-a[i]])%mod;
		asd=(dp[m]+asd)%mod;
	}
	printf("%lld\n",asd);
}