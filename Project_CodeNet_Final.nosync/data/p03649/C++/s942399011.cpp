#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll ans = 0;
	for (int iter = 0; iter < 1000000; iter++) {
		for (int i = 0; i < n; i++) {
			if (a[i] >= n) {
				ll cnt = a[i] / n;
				ans += cnt;
				a[i] -= cnt*n + cnt;
				for (int j = 0; j < n; j++) {
					a[j] += cnt;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
