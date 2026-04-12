#include <bits/stdc++.h>
using namespace std;

int n, K;
long long Ans = 0;

void Init()
{
	scanf("%d%d", &n, &K);
}

void Solve()
{
	for (int i = K + 1; i <= n; ++i) {
		Ans += max(0, (n % i) - K + 1);
		Ans += (n / i) * (i - K);
		if (K == 0) --Ans;
	}
	printf("%lld\n", Ans);
}

int main()
{
	Init();
	Solve();
	return 0;
}
