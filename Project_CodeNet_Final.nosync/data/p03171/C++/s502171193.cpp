#include <iostream>
#include <stdio.h>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

const int N = 3e3 + 1;
const int K = 1e5 + 1;
const int MOD = 1e9 + 7;

int a[N];
long long DP[N][N];
bool have[N][N];
int n;

// X - Y
long long dp(int l, int r) {
	if (l == r) {
		return 0;
	}
	int turn = (l + r + n) % 2;
	if (have[l][r])
		return DP[l][r];
	if (turn == 0) {
		long long ans = max(a[l] + dp(l + 1, r), a[r - 1] + dp(l, r - 1));
		have[l][r] = true;
		return DP[l][r] = ans;
	} else {
		long long ans = min(dp(l + 1, r) - a[l], dp(l, r - 1) - a[r - 1]);
		have[l][r] = true;
		return DP[l][r] = ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << dp(0, n) << "\n";
	return 0;
}