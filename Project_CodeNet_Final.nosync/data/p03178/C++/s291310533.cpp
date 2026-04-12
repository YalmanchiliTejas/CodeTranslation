#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()

string s;
ll dp[11000][110][2],N;
int main() {
	dp[0][0][0] = 1;
	cin >> s >> N;
	REP(i, s.size()) {
		REP(l, N) {
			REP(j, 2) {
				int a = j ? 9 : s[i] - '0';
				REP(k, a + 1) {
					dp[i + 1][(l + k) % N][j or k < a] += dp[i][l][j];
					dp[i + 1][(l + k) % N][j or k < a] %= 1000000007;

				}
			}
		}
	}
	ll ans = -1;
	REP(i, 2) ans += dp[s.size()][0][i];
	cout << (ans + 1000000007) % 1000000007 << endl;
}