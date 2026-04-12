#include <bits/stdc++.h>
using namespace std;
int n, k;
long long tot = 0;
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> k;
	for (int b = k + 1; b <= n; b++)
	{
		int x = n / b, y = n % b;
		tot += 1LL * x * (b - k);
		tot += y >= k? y - k + 1 : 0;
	}
	if (!k) tot -= n;
	cout << tot << endl;
	return 0;
}