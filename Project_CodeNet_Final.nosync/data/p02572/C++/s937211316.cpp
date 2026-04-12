#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

const ll Mod = 1e9 + 7, N = 200010;
ll a[N], tot  = 0;

int main()
{
	int n;
	scanf("%d%d", &n, &a[1]);
	a[1] %= Mod;
	for (int i = 2; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
		tot = (((a[i] * a[i - 1]) % Mod ) + tot) % Mod;
		a[i] = (a[i] + a[i - 1]) % Mod;
	}
	printf("%lld\n", tot);
	
	return 0;
}