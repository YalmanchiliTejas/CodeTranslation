#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll dp[102][4][2];


int main() {
	string s;
	ll K;
	cin >> s >> K;

	dp[0][0][0] = 1;

	rep(i, s.size()) {
		int cur = s[i] - '0';
		rep(j, K + 1) {
			rep(k, 2) {
				rep(d , 10) {
					int ni = i + 1, nj = j, nk = 1;
					if (d != 0) {
						nj ++;
					}
					if (nj > K) {
						continue;
					}
					if (cur < d && k == 0) {
						continue;
					}

					if (cur == d && k == 0) {
						nk = 0;
					}
					dp[ni][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
	
	cout << dp[s.size()][K][0] + dp[s.size()][K][1] << endl;
	return 0;
}