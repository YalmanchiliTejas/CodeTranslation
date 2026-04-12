#include <iostream>
#include <algorithm>

long long b[60], h[60], n, r, ans;

void solve(int now)
{
	if (r <= 0) return;
	if (!now) { --r, ++ans; return; }
	if (r >= h[now]) { r -= h[now], ans += b[now]; return; } 
	--r;
	if (r > 0) solve(now - 1);
	if (r > 0) ++ans, --r;
	if (r > 0) solve(now - 1);
	--r;
}

int main()
{
	scanf("%lld%lld", &n, &r);
	h[0] = 1, b[0] = 1;
	for (int i = 1; i <= 50; ++i) h[i] = (h[i - 1] << 1) + 3, b[i] = 1 + (b[i - 1] << 1);
	solve(n); 
	std::cout << ans;
	return 0;
}