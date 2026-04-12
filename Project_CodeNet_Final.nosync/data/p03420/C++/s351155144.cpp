#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define N 100005
#define ll long long
#define db double
#define dbg(x) cout<<#x<<"="<<x<<"\n"
int n,m;ll ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=m+1;i<=n;i++)
	{
		ans+=n/i*(i-m);
		if(n%i>=m) ans+=n%i-m+1;
//		cout<<i<<" "<<ans<<"\n";
	}
	if(!m) ans-=n;
	printf("%lld\n",ans);
	return 0;
}
