#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

ll md = (ll)1e9 + 7;

int main()
{
	int N;
	cin >> N;
	vector<ll> A(N, 0);
	vector<ll> sm(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	for (int i = N - 2; i >= 0; --i) {
		sm[i] = (sm[i + 1] + A[i + 1]) % md;
	}

	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += (A[i] * sm[i]) % md;
		ans = ans % md;
}

	cout << ans << endl;
	return 0;
}
