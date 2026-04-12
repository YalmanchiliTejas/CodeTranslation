#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll pre[N][2] = {0}, aft[N][2] = {0};
ll a[N];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	scanf("%lld", a+i);
	if(n % 2)
	{
		ll res = -1e18;
		for(int i = 2; i <= n; i+=2)
		{
			pre[i][0] = pre[i-2][0] + a[i - 1];
			pre[i][1] = max(pre[i - 2][0], pre[i - 2][1]) + a[i];
		}
		for(int i = n; i >= 1; i-=2)
		{
			aft[i][0] = max(aft[i+2][0], aft[i + 2][1]) + a[i - 1];
			aft[i][1] = aft[i + 2][1] + a[i];
		}
		for(int i = 1; i <= n; i+=2)
		{
			res = max(res, max(pre[i-1][0], pre[i-1][1]) + max(aft[i + 2][0], aft[i + 2][1]));
		}
		printf("%lld\n", res);
	}else
	{
		for(int i = 2; i <= n; i+=2)
		{
			pre[i][0] = pre[i-2][0] + a[i - 1];
			pre[i][1] = max(pre[i - 2][0], pre[i - 2][1]) + a[i];
			
		}
		printf("%lld\n", max(pre[n][0], pre[n][1]));
	}
} 