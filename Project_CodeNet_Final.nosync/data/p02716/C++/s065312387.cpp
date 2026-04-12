#include "bits/stdc++.h"
#include <random>
using namespace std; typedef unsigned long long _ulong; typedef long long int lint; typedef pair<lint, lint> plint; typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define endk '\n'
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const lint MOD = 1e9 + 7, INF = 1e18;
lint dx[8] = { 0, -1, 1, 0, 1, -1, 1, -1 }, dy[8] = { 1, 0, 0, -1, -1, -1, 1, 1 };

lint N, arr[200000], sum = 0, odd_sum = 0;
lint dp[200100][5];
int main() {
	cin >> N;
	REP(i, N) {
		cin >> arr[i];
		sum += arr[i];
		if (i % 2 == 0) odd_sum += arr[i];
	}
	REP(i, N + 10) {
		REP(j, 3) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	REP(i, N) {
		REP(j, 3) {
			REP(k, 3) {
				chmax(dp[i + 1][k + 1], dp[i][k]);
				chmax(dp[i + 2][k], dp[i][k] + arr[i]);
				chmax(dp[i + 3][k + 1], dp[i][k] + arr[i + 1]);
				chmax(dp[i + 4][k + 2], dp[i][k] + arr[i + 2]);
			}
		}
	}
	lint ans = -INF;
	if (N == 2) { cout << max(arr[0], arr[1]) << endk; }
	else if (N == 3 || N % 2 == 0) {
		REP(i, 3) {
			chmax(ans, dp[N + i][1]);
		}
		cout << ans << endk;
	}
	else {
		REP(i, 3) {
			chmax(ans, dp[N + i][2]);
		}
		cout << ans << endk;
	}


}