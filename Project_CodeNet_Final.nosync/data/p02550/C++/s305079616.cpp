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

ll N, X, M;

int main() {

	cin >> N >> X >> M;

	if (N <= 112345) {
		ll ans = 0;
		ll A = X;
		rep(i, N) {
			ans += A;
			A = A * A % M;
		}
		cout << ans << endl;
		return 0;
	}

	map<ll, ll> E;
	ll A = X;
	ll lb = 0, le = 1;
	rep(i, N) {
		if (E.find(A) == E.end()) {
			E[A] = i;
			A = A * A % M;
		}
		else {
			lb = E[A];
			le = i;
			break;
		}
	}

	ll pre = 0, loop = 0, end = 0, endc = (N - lb) % (le - lb);

	A = X;
	rep(i, lb) {
		pre += A;
		A = A * A % M;
	}

	rep(i, le - lb) {
		if (i < endc) end += A;
		loop += A;
		A = A * A % M;
	}

	cout << pre + loop * ((N - lb) / (le - lb)) + end << endl;

	return 0;
}
