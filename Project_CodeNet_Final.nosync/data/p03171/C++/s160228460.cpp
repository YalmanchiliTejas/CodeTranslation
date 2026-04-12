#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
#include <math.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1000000007;
const int INF = 1000000007;
const double EPS = 1e-10;
const double PI = 3.14159265359;
const int N = 100005;
//cout << fixed << std::setprecision(9)
//--------------------------

int n;
ll a[3003];
ll dp[3003][3003];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i][i] = a[i];
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (i + k >= n) continue;

			if (k == 0) {
				dp[i][i] = a[i];
			}
			else if (k == 1) {
				dp[i][i + 1] = max(a[i], a[i + 1]) - min(a[i], a[i + 1]);
			}
			else {
				// left
				ll l = a[i] + min(dp[i + 2][i + k] - a[i + 1], dp[i + 1][i + k - 1] - a[i + k]);

				// right
				ll r = a[i + k] + min(dp[i + 1][i + k - 1] - a[i], dp[i][i + k - 2] - a[i + k - 1]);

				dp[i][i + k] = max(l, r);
			}
		}
	}

	cout << dp[0][n - 1] << endl;

	return 0;
}