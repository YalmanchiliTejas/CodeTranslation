#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	ll cnt = 0;
	if (k == 0) return !printf("%lld", (ll)n*(ll)n);
	for (int i = k + 1; i <= n; i++)
	{
		int can = i - k;
		cnt += n / i * can;
		cnt += max(0, n - n / i * i - k + 1);
	}
	return !printf("%lld", cnt);
}