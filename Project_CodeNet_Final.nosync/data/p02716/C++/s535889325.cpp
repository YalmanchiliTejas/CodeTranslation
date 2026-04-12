#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <time.h>
#include <bitset>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }

map<pair<ll, ll>, ll> memo;
ll N, A[212345];

ll dp(ll i, ll n) {
	if (n == 0) return 0;
	if (i < 2 * (n - 1)) return -2123450000000000;
	if (memo.find({ i, n }) != memo.end()) return memo[{i, n}];
	return memo[{i, n}] = max(dp(i - 1, n), dp(i - 2, n - 1) + A[i]);
}

int main() {

	cin >> N;
	rep(i, N) cin >> A[i];

	cout << dp(N - 1, N / 2) << endl;

	return 0;
}
