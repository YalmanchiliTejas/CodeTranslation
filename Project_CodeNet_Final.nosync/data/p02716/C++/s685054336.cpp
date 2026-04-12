#include <bits/stdc++.h>
using namespace std;
int main() {
// Time Complexity: O(N)
// Space Complexity: O(N)
int n;
cin >> n;
long a[n + 1], dp[n + 1], odds[n + 1];
dp[0] = dp[1] = 0;
for (int i = 1; i <= n; ++i) cin >> a[i];
for (int i = 1; i <= n; i += 2)
odds[i] = (i == 1 ? 0 : odds[i - 2]) + a[i];
for (int i = 2; i <= n; ++i)
dp[i] = max(a[i] + dp[i - 2], i % 2 ? dp[i - 1] : odds[i - 1]);
cout << dp[n] << '\n';
return 0;
}