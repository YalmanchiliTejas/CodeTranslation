#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2 * 100 * 1000  + 20;
ll n, sum[N], dp[N], a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		sum[i] = a[i] + (i > 1? sum[i - 2]: 0);
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0)
			dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
		else
			dp[i] = max(a[i] + dp[i - 2], sum[i - 1]);
	}
	return cout << dp[n - 1] << endl, 0;
}	
