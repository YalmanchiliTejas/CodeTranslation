#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <functional>
#include <algorithm>
#include <utility>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <complex>

using namespace std;

typedef long double C;
typedef complex<C> P;

#define have(X, Y) (X).find(Y) != (X).end()
#define X real()
#define Y imag()
#define ui unsigned int
#define int long long
#define mp make_pair
#define timer fghge
#define y1 yjyjyju
#define all(X) (X).begin(), (X).end()
#define endl "\n"

const int mod = 998244353;

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("search5.out", "w", stdout);

	int n, s; cin >> n >> s;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	vector<vector<int>> dp(n, vector<int>(s + 1));
	for (int j = 0; j <= s; j++) {
		if (a[0] == j)
			dp[0][j] = 1;		
	}
	int ans = dp[0][s];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= s; j++) {			
			dp[i][j] = dp[i - 1][j];
			if (a[i] == j)
				dp[i][j] += i + 1;
			dp[i][j] %= mod;
			if (a[i] <= j) 
				dp[i][j] += dp[i - 1][j - a[i]];
			dp[i][j] %= mod;
		}
		ans += dp[i][s];
		ans %= mod;
	}
	cout << ans;
	return 0;
}