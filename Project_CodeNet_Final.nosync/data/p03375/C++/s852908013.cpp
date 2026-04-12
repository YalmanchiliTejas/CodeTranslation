#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

// a종류 토핑이 1개 이하인 경우의 수->그 중 b 종류가 1개인 경우의 수-> nCa * aCb * partitionv(a, b) * 2 ^ (2 ^ (n - a) - 1)
// partitionv(a, b) = sigma k, 1~b partition(b, k) * (2^(n-a))^k
// ans = sigma a, sigma b, sigma k, nCa * aCb * partition(b, k) * (2^(n-a))^k * 2 ^ (2^(n-a) - 1) 
ll mypow(ll a, ll b, ll m) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = rv*a%m;
		a = a*a%m;
		b /= 2;
	}
	return rv;
}

ll Co[3050][3050];
ll part[3050][3050];
int main() {
	ll N, M, i, j, k;
	scanf("%lld %lld", &N, &M);

	for (i = 0; i <= 3000; i++) {
		Co[i][0] = Co[i][i] = 1;
		for (j = 1; j < i; j++) Co[i][j] = (Co[i - 1][j - 1] + Co[i - 1][j]) % M;
	}
	part[0][0] = 1;
	for (i = 1; i <= 3000; i++) {
		for (j = 0; j <= i; j++) {
			part[i][j] = part[i - 1][j] * (j + 1);
			if (j) part[i][j] += part[i - 1][j - 1];
			part[i][j] %= M;
		}
	}

	ll ans = 0;
	for (ll a = 0; a <= N; a++) {
		ll tv1 = mypow(2, (N - a), M);
		ll tv = mypow(2, mypow(2, N - a, M - 1), M) % M;
		for (ll k = 0; k <= a; k++) {
			ll v = Co[N][a];
			v = v * part[a][k] % M;
			v = v * tv % M;
			if (a % 2) v = M - v;

			ans = (ans + v) % M;
			tv = (tv * tv1) % M;
		}
	}
	return !printf("%lld\n", ans);
}