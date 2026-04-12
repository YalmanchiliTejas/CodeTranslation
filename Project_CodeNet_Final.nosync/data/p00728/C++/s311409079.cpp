#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 5100000;
const long long INF = 1LL << 60;
const long long mod = 1000000007LL;
//const long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/

	ll n;
	while (1) {
		ll n; scanf("%lld", &n);
		if (n == 0) break;
		vector<ll> a(n); for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);
		sort(a.begin(), a.end());
		ll sum = 0;
		for (ll i = 1; i < n - 1; i++) sum += a[i];
		sum /= (n - 2);
		printf("%lld\n", sum);
	}
	return 0;
}

