#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, k, x, i, ans;
int main()
{
	cin >> n >> k;
	for (i = k + 1; i <= n; i++) {
		x = n / i;
		ans += x * (i - k);
		if (k == 0) ans += n - (x * i);
		else ans += max(0LL, n - (x * i + k) + 1);
	}
	cout << ans;
    return 0;
}
