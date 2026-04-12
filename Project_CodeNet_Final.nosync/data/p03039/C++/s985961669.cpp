/*
ID: jerrywcy
LINK: https://atcoder.jp/contests/abc127/tasks/abc127_e
LANG: C++
STATUS:
*/
#include <bits/stdc++.h>

#define int long long
#define init(array,x) memset(array,x,sizeof(array))

using namespace std;

const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxnm=2e5+10;

int n,m,k;
int fac[maxnm],inv_fac[maxnm];
int ans;

int p(int x,int y){
	long long ret=1,mul=x;
	while (y){
		if (y&1)ret=(ret*mul)%mod;
		mul=(mul*mul)%mod;
		y>>=1;
	}
	return ret;
}

void pre(){
	fac[0]=1;
	for (int i=1;i<=n*m;i++)fac[i]=(fac[i-1]*i)%mod;
	inv_fac[n*m]=p(fac[n*m],mod-2);
	for (int i=n*m-1;i>=0;i--)inv_fac[i]=(inv_fac[i+1]*(i+1))%mod;
	return ;
}

int C(int x,int y){
	if (y==0 || y==x)return 1;
//	cout<<fac[x]<<' '<<inv_fac[y]<<' '<<inv_fac[x-y]<<endl;
	return ((inv_fac[y]*inv_fac[x-y])%mod*fac[x])%mod;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	pre();
//	for (int i=1;i<n;i++){
//		long long tmp=1ll*i*(i+1)/2%mod;
//		tmp=tmp*m*m%mod;
//		ans=(ans+tmp)%mod;
//	}
//	for (int i=1;i<m;i++){
//		long long tmp=1ll*i*(i+1)/2%mod;
//		tmp=tmp*n*n%mod;
//		ans=(ans+tmp)%mod;
//	}
//	cout<<p(m,2*n-2)<<' '<<p(n,2*m-2)<<endl;
	long long ans=((m*m%mod)*(((n-1)*n*(2*n-1)/6%mod+n*(n-1)/2%mod)%mod)%mod)*(500000004)%mod+
	              ((n*n%mod)*(((m-1)*m*(2*m-1)/6%mod+m*(m-1)/2%mod)%mod)%mod)*(500000004)%mod;
//	cout<<ans<<endl;
//	cout<<C(n*m-2,k-2)<<endl;
	ans=(ans*C(n*m-2,k-2))%mod;

	cout<<ans<<endl;

	return 0;
}
