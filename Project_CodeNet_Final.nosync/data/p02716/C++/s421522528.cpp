#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cassert>
#define InfL 1000000000
#define InfLL 1000000000000000000LL
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n-1);(i)>=(0);(i)--)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<db> vd;

int main() {
	ll N;
	cin >> N;
	int consecutive_not_max = (N % 2 == 0) ? 2 : 3;
	vl A(N);
	rep(i, N)
		cin >> A[i];
	vector<vector<vl>> DP(N + 1);
	rep(i, N + 1) {
		DP[i].resize(consecutive_not_max);
		rep(j, consecutive_not_max) {
			// 0 : i番目を選ばない (out)
			// 1 : i番目を選ぶ (in)
			DP[i][j].resize(2, -InfLL);
		}
	}
	DP[0][0][0] = 0;
	rep(i, N) {
		rep(j, consecutive_not_max) {
			// out - in
			DP[i + 1][j][1] = max(DP[i + 1][j][1], DP[i][j][0] + A[i]);
			// out - out
			if (j + 1 != consecutive_not_max)
				DP[i + 1][j + 1][0] = max(DP[i + 1][j + 1][0], DP[i][j][0]);
			// in - out
			DP[i + 1][j][0] = max(DP[i + 1][j][0], DP[i][j][1]);
		}
	}
	ll ans = max(DP[N][consecutive_not_max - 2][0], DP[N][consecutive_not_max - 1][1]);
	cout << ans << endl;
	return 0;
}