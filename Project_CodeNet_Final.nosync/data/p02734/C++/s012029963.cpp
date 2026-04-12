#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////




int main() {

	ll N, S;
	cin >> N >> S;

	vector<ll> A(N + 1);
	repn(i, N) cin >> A[i];

	vector<vector<ll>> dp(N + 1, vector<ll>(S + 1, 0));

	repn(i, N)dp[i][0] = 1;

	repn(i, N)repn(j, S) {
		if (j < A[i]) { dp[i][j] = dp[i - 1][j]; }
		if (j == A[i]) {
			dp[i][j] = dp[i - 1][j] + i;
		}
		if (j > A[i]) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - A[i]];
		}

		dp[i][j] %= MOD;
	}

	ll ans = 0;

	repn(i, N) {
		ll X = dp[i][S] - dp[i - 1][S];
		X *= (N - i + 1);
		ans += X;
		ans %= MOD;
		if (ans < 0) { ans += MOD; }
	}

	cout << ans;

	system("PAUSE");

}
