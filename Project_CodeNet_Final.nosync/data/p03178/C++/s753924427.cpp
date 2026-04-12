#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()

ll dp[10010][2][110];


int main()
{
	string K; int D;
	cin >> K >> D;

	ll MOD = 1e9 + 7;
	rep(i, K.size() + 1)rep(j, 2)rep(k, D)dp[i][j][k] = 0;
	dp[0][0][0] = 1;

	rep(i, K.size()) {
		int d = K[i] - '0';
		rep(j, 2) {
			rep(k, D)rep(l, (j ? 10: d + 1)) {
				dp[i + 1][j || (l < d)][(k + l) % D] += dp[i][j][k];
				dp[i + 1][j || (l < d)][(k + l) % D] %= MOD;
			}
		}
	}
	cout << (dp[K.size()][0][0] + dp[K.size()][1][0] + MOD - 1) % MOD << endl;
}
