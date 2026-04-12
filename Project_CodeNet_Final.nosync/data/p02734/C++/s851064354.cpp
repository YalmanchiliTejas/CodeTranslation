#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

//const ll MOD_CONST = 1000000007;
const ll MOD_CONST = 998244353;


const int INF = 1000000000;
const ll BIG_NUM = 1000000000000000000;



int main() {
	int n, s;
	cin >> n >> s;

	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(s + 1, vector<ll>(3)));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= s; j++) {
			(dp[i + 1][j][0] += dp[i][j][0]) %= MOD_CONST;
			(dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD_CONST;
			(dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= MOD_CONST;

			if (a[i] + j <= s) {
				(dp[i + 1][a[i] + j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD_CONST;
				(dp[i + 1][a[i] + j][2] += dp[i][j][0] + dp[i][j][1]) %= MOD_CONST;
			}
		}


	}



	cout << dp[n][s][2] << endl;
}

