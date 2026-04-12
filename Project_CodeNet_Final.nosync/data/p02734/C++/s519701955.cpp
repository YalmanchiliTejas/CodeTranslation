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
#define mod 998244353
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
	int N, S;
	cin >> N >> S;
	vl A(N);
	rep(i, N)
		cin >> A[i];
	vector<vl> DP(N + 1);
	rep(i, N + 1)
		DP[i].resize(S + 3, 0); // 0~S : 処理中で和がi, S+1 : 左端未確定, S+2 : 右端確定
	DP[0][S + 1] = 1;

	rep(i, N) {
		ll Atmp = A[i];
		rep(j, S + 1) {
			DP[i + 1][j] += DP[i][j]; // 選ばない
			DP[i + 1][j] %= mod;
			ll jnxt = j + Atmp;
			if (jnxt > S)
				continue;
			DP[i + 1][jnxt] += DP[i][j]; // 選ぶ
			DP[i + 1][jnxt] %= mod;
		}
		DP[i + 1][0] += DP[i][S + 1]; // 左端 : i, 選ばない
		DP[i + 1][0] %= mod;
		if (Atmp <= S) {
			DP[i + 1][Atmp] += DP[i][S + 1]; // 左端 : i, 選ぶ
			DP[i + 1][Atmp] %= mod;
		}
		DP[i + 1][S + 1] += DP[i][S + 1]; // 左端 : >i
		DP[i + 1][S + 1] %= mod;
		DP[i + 1][S + 2] += DP[i][S]; // 右端 : i, 選ばない
		DP[i + 1][S + 2] %= mod;
		if (S - Atmp >= 0) {
			DP[i + 1][S + 2] += DP[i][S - Atmp]; // 右端 : i, 選ぶ
			DP[i + 1][S + 2] %= mod;
		}
		if (S - Atmp == 0) {
			DP[i + 1][S + 2] += DP[i][S + 1]; // 左端,右端 : i, 選ぶ
			DP[i + 1][S + 2] %= mod;
		}
		DP[i + 1][S + 2] += DP[i][S + 2]; // 右端 : <i
		DP[i + 1][S + 2] %= mod;
	}

	ll ans = DP[N][S + 2];
	cout << ans << endl;
	return 0;
}