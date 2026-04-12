#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ll;

int n;
int a[3010];
ll dp[3010][3010];

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = n; i >= 1; i--)
		for (int j = i; j <= n; j++)
			dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);

	printf("%lld", dp[1][n]);

	return 0;
}