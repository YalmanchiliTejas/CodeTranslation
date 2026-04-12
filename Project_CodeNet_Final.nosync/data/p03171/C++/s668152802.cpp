#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <iomanip>

using namespace std;

const int maxn = 3002;

int n, a[maxn];
long long sum[maxn], f[maxn][maxn];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i][i] = a[i];
		sum[i] = sum[i-1] + a[i];
	}

	for (int len = 2; len <= n; ++len)
		for (int i = 1; i <= n+1-len; ++i) {
			int j = i + len - 1;
			f[i][j] = sum[j] - sum[i-1] - min(f[i+1][j], f[i][j-1]);
		}

	long long ans = f[1][n] * 2 - sum[n];
	
	cout << ans << endl;

	return 0;
}