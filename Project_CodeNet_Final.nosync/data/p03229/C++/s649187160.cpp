#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (n % 2 == 0) {
		ll sum = 0;
		for (int i = 0; i < n / 2; i++) {
			sum -= a[i];
		}
		for (int i = n / 2; i < n; i++) {
			sum += a[i];
		}
		ll ans = 2 * sum;
		ans += a[n / 2 - 1];
		ans -=a[n / 2];
		cout << ans << endl;
		return 0;
	}
	ll sum = 0;
	for (int i = 0; i < n / 2; i++) {
		sum -= a[i];
	}
	for (int i = n / 2 + 1; i < n; i++) {
		sum += a[i];
	}
	ll ans = 2 * sum;
	ans += max(a[n / 2] - a[n / 2 + 1], a[n / 2 - 1] - a[n / 2]);
	cout << ans << endl;
	return 0;

}