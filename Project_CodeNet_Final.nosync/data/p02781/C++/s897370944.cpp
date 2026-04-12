#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 100005;
//////////////////////////////

string s;
int dig[102];
int k, n;
int dp[102][4];
int dp2[102][4];//equal

void solve()
{
	cin >> s;
	cin >> k;
	n = s.size();
	for (int i = 0; i < n; i++) {
		dig[i] = (s[i] - '0');
	}

	//init
	if (dig[0] == 0) {
		dp2[1][0] = 1;
	}
	else {
		dp[1][1] = dig[0] - 1;
		dp[1][0] = 1;
		dp2[1][1] = 1;
	}

	for (int i = 1; i < n; i++) {
		//equal
		if (dig[i] == 0) {
			for (int j = 0; j <= k; j++)
				dp2[i + 1][j] = dp2[i][j];
		}
		else {
			for (int j = 1; j <= k; j++)
				dp2[i + 1][j] = dp2[i][j - 1];
		}

		//less
		for (int d = 0; d < 10; d++) {
			if (d == 0) {
				for (int j = 0; j <= k; j++) {
					dp[i + 1][j] += dp[i][j];
				}
			}
			else {
				for (int j = 1; j <= k; j++) {
					dp[i + 1][j] += dp[i][j - 1];
				}
			}
		}

		for (int d = 0; d < dig[i]; d++) {
			if (d == 0) {
				for (int j = 0; j <= k; j++) {
					dp[i + 1][j] += dp2[i][j];
				}
			}
			else {
				for (int j = 1; j <= k; j++) {
					dp[i + 1][j] += dp2[i][j - 1];
				}
			}
		}
	}

	cout << dp[n][k] + dp2[n][k] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
