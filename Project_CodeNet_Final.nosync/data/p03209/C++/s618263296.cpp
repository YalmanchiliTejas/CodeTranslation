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
const ll maxn = 55;
ll a[maxn],p[maxn];
ll fon(ll n,ll x)
{
	if(n == 0)
	{
		return x > 0;
	}
	else if(x <= 1 + a[n - 1])
	{
		return fon(n - 1,x - 1);
	}
	else
	{
		return p[n - 1] + 1 + fon(n - 1,x - 2 - a[n - 1]);
	}
}
void init()
{
	for(ll i = 1;i < maxn; ++i)
	{
		a[i] = a[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
}
int main(int argc, char const *argv[])
{
	ll n,x;
	a[0] = p[0] = 1;
	init();
	cin>>n>>x;
	printf("%lld\n",fon(n,x));
	return 0;
}
