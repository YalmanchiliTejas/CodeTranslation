#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;
const int oo = 2e9;
int n, a[N], dp[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] = -a[i];
	}
	vector<int> dp;
	for(int i = 1; i <= n; i++) {
		auto it = upper_bound(dp.begin(), dp.end(), a[i]);
		if(it == dp.end()) dp.push_back(a[i]);
		else dp[it - dp.begin()] = a[i];
	}
	printf("%d\n", (int)dp.size());
	return 0;
}