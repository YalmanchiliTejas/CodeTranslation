#include <iostream>
#include <cstdio>
#include <cstring>

typedef long long ll;
ll n, x, ans, h[60], p[60];

void sovle(int now)
{
	if (x <= 0) return;
	if (!now)
	{
		--x;
		++ans;
		return;
	}
	if (x >= h[now])
	{
		x -= h[now];
		ans += p[now];
		return;
	}
	--x;
	if (x > 0) sovle(now - 1);
	if (x > 0) ++ans, --x;
	if (x > 0) sovle(now - 1);
	--x;
}

int main()
{
	scanf("%lld%lld", &n, &x);
	h[0] = 1, p[0] = 1;
	for (int i = 1; i <= 50; ++i) h[i] = (h[i - 1] << 1) + 3, p[i] = (p[i - 1] << 1) + 1;
	sovle(n);
	printf("%lld", ans);
	return 0;
}