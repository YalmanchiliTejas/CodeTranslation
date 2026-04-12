#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pr(x) cerr<<#x<<"="<<(x)<<endl
#define pri(x,lo) {cerr<<#x<<"={";for (int ol=0;ol<=lo;ol++)cerr<<x[ol]<<",";cerr<<"}"<<endl;}
#define inf 100000000
#define N 1000
ll n,k,ans,b,i;
int main()
{
	scanf("%lld %lld",&n,&k);
	if (k==0)
	{
		printf("%lld\n",n*n);
		return 0;
	}
	for (i=k;i<=n;i++)
	{
		//pr(i);pr(n/i*(i-k));pr(max(0,n%i-k+1));
		ans+=n/i*(i-k);
		ans+=max(0ll,n%i-k+1);
	}
	printf("%lld\n",ans);
	return 0;
}