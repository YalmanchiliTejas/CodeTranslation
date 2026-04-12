/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int b = k + 1; b <= n; ++b) {
		ll cyc = (n + 1) / b;
		ll rem = n + 1 - b * cyc;
		ans += cyc * (b - k);
		ans += max(0ll, rem - k);
	}
	if (!k) {
		ans -= n;
	}
	cout << ans << endl;
}