#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1e5 + 5;
ll a[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll ans1 = 0,ans2 = 0;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	ll l = 1,r = n,x = a[(n + 1) / 2];
	for(ll i = 1;i < n; ++i)
	{
		if(i & 1)
		{
			ans1 += abs(a[l] - x);
			x = a[l++];
		}
		else
		{
			ans1 += abs(a[r] - x);
			x = a[r--];
		}
	}
	l = 1,r = n,x = a[(n + 1) / 2];
	for(ll i = 1;i < n; ++i)
	{
		if(i & 1)
		{
			ans2 += abs(a[r] - x);
			x = a[r--];
		}
		else
		{
			ans2 += abs(a[l] - x);
			x = a[l++];
		}
	}
	printf("%lld\n",max(ans1,ans2));
	return 0;
}