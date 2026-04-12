#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int b = k + 1; b <= n; b++)
		for (int a = 0; a <= n; a += b) {
			int from = a + k, to = min(n + 1, a + b);
			if (from == 0) from++;
			if (from < to) res += to - from;
		}
	cout << res << endl;
	return 0;
}