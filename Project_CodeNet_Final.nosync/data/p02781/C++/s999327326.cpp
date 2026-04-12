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
#define Inf 1000000000
#define nmax_def 110000
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

int main() {
	string N;
	cin >> N;
	int K;
	cin >> K;
	int Nlen = N.length();
	ll ans = 0;
	vector<vector<vl>> DP(Nlen+1);
	rep(i, Nlen + 1) {
		DP[i].resize(2);
		rep(d, 2) { // 0 or other
			DP[i][d].resize(K + 1, 0);
		}
	}

	DP[0][0][0] = 1;

	rep(i, Nlen) {
		rep(k, K + 1) {
			DP[i + 1][0][k] += DP[i][0][k] + 9 * DP[i][1][k];
			if (k != K)
				DP[i + 1][1][k + 1] += DP[i][0][k] + 9 * DP[i][1][k];
		}
	}

	int count_not_zero = 0;
	rep(i, Nlen) {
		int n = (int)N[i] - (int)'0';
		if (i == Nlen - 1)
			n++;
		rep(d, n) {
			if (d == 0)
				ans += DP[Nlen - i][0][K - count_not_zero];
			else
				ans += DP[Nlen - i][1][K - count_not_zero];
		}
		if (n != 0)
			count_not_zero++;
		if (K - count_not_zero < 0)
			break;
	}
	ans -= DP[0][0][K]; // K != 0 なので無意味

	cout << ans << endl;

	return 0;
}