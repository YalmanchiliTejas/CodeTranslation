#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;


int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);

	ll ans = 0;
	for (ll b = k + 1; b <= n; b++) {
		ll mk = n - n / b * b;
		if (mk + 1 <= k) ans += (n / b) * (b - k);
		else ans += (n / b + 1) * (mk - k + 1) + (n / b) * (b - mk - 1);

		// printf("%lld %lld %lld\n", b, mk, ans);
	}

	if (k == 0) ans -= n;
	printf("%lld", ans);
}