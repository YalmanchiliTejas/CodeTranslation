#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 110;

ll n;
ll a[maxn];
ll ans;

int main()
{
	scanf("%lld",&n); for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	
	ans=0ll;
	if(a[1]>=n)
	{
		ans=a[1]-n+1ll;
		for(int i=1;i<=n;i++) a[i]-=ans;
		ans*=n;
	}
	for(int i=n;i>=2;i--)
	{
		ll x=a[i-1],y=a[i];
		if(y-x>=n)
		{
			ll tmp=n+1ll; //n-i+1
			ll temp=(y-x-(n-1ll)+tmp-1ll)/tmp;
			
			ll dec=temp*(ll)(n-i+1); ans+=dec;
			for(int j=1;j<i;j++) a[j]+=dec;
			for(int j=i;j<=n;j++) a[j]-=(ll)i*temp;
		}
		sort(a+1,a+n+1);
	}
	if(a[1]>=n)
	{
		ll temp=a[1]-n+1ll;
		ans+=n*temp;
		for(int i=1;i<=n;i++) a[i]-=temp;
	}
	while(a[n]>=n)
	{
		ll temp=a[n]/n; ans+=temp; a[n]-=temp*n;
		for(int i=1;i<n;i++) a[i]+=temp;
		sort(a+1,a+n+1);
	}
	printf("%lld\n",ans);
	
	return 0;
}
