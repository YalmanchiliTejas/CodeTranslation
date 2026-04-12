#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cassert>

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define PI acos(-1.0)

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vll;

int main() {
	//freopen("maxrand1.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll arr[50];
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ll ans = 0;
	while (true) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (sum > 10000000000000000)
				break;
		}		
		if (sum <= n * (n - 1)) break;
		ll step = n * (1 - n) + sum;
		ll old = step;
		ans += step;
		for (int i = 0; i < n; i++) {
			ll tmp = step;
			ll l = 0, r = step;
			while (l <= r) {
				ll mid = (l + r) / 2;
				if (arr[i] - mid * n + old - mid >= 0) {
					tmp = mid;
					l = mid + 1;
				} else r = mid - 1;
			}
			arr[i] = arr[i] - tmp * n + old - tmp;
			step -= tmp;
		}
	}
	while (true) {
		ll toAdd = 0;
		for (int i = 0; i < n; i++) toAdd += arr[i] / n;
		if (toAdd == 0)
			break;
		ans += toAdd;
		for (int i = 0; i < n; i++) {
			arr[i] = arr[i] % n + toAdd - arr[i] / n;
		}
	}
	cout << ans << endl;
	return 0;
}
