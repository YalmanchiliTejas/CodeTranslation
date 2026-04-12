#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(ll i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep (i, n) cin >> a[i];
	sort(all(a));
	ll ans = 0;
	if (n % 2 == 0) {
		rep (i, n) {
			if (i < n / 2 - 1) {
				ans -= 2 * a[i];
			} else if (i < n / 2) {
				ans -= a[i];
			} else if (i == n / 2) {
				ans += a[i];
			} else {
				ans += 2 * a[i];
			}
		}
	} else {
		ll tmp = 0;
		// ue n/2 - 1
		rep (i, n) {
			if (i < n / 2 - 1) {
				ans -= 2 * a[i];
			} else if (i < n / 2 + 1) {
				ans -= a[i];
			} else {
				ans += 2 * a[i];
			}
		}
		rep (i, n) {
			if (i < n / 2) {
				tmp -= 2 * a[i];
			} else if (i < n / 2 + 2) {
				tmp += a[i];
			} else {
				tmp += 2 * a[i];
			}
		}
		chmax(ans, tmp);
	}
	cout << ans << "\n";
	return 0;
}