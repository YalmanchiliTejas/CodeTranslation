#include <iostream>
#include <cstring>
using namespace std;
long long a[200005], sum[200005];
long long dp[200005];
int main() {
    int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum[i] = a[i] + (i > 1? sum[i - 2]: 0);
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0)
			dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
		else
			dp[i] = max(a[i] + dp[i - 2], sum[i - 1]);
	}
    cout << dp[n - 1] << endl;
	return 0;
}