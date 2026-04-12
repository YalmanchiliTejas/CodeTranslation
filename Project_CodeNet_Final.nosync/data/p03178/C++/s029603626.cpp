#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int mod = 1000000007;
string s;
int d;
int dp[10001][2][2][100];	//dp[keta][up-clear?][down-clear?][mod d]

signed main() {
	int i, j, k, l, m;
	
	cin >> s >> d;
	dp[0][0][0][0] = 1;
	
	rep(i, s.length()) {
		rep(j, 2) {
			rep(k, 2) {
				rep(l, d) {
					rep(m, 10) {
						if (j == 0 && m > s[i] - '0') continue;
						dp[i + 1][j || (m < (s[i] - '0'))][k || m != 0][(l + m) % d] += dp[i][j][k][l];
						dp[i + 1][j || (m < (s[i] - '0'))][k || m != 0][(l + m) % d] %= mod;
					}
				}
			}
		}
	}
	
	int ans = 0;
	rep(j, 2) ans += dp[s.length()][j][1][0];
	ans %= mod;
	cout << ans << endl;
	return 0;
}