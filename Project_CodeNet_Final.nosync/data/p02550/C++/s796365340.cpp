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
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;



int main() {
	ll n, x, m;
	cin >> n >> x >> m;

	ll a = x;
	set<ll> s;
	int c = 0;
	
	while (s.find(a) == s.end()) {
		c++;
		s.insert(a);
		a = (a * a) % m;
	}

	if (c >= n) {
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += x;
			x = (x * x) % m;
		}
		cout << ans << endl;
		return 0;
	}

	ll ans = 0;
	ll c_begin = 0;
	
	ll c_sum = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		c_sum += *it;
	}

	for (int i = 0; i < n; i++) {
		if (x == a) {
			c_begin = i;
			break;
		}
		ans += x;
		
		x = (x * x) % m;
		
	}
	ll c_len = c - c_begin;
	c_sum -= ans;
	n -= c_begin;
	ans += c_sum * (n / c_len);
	n %= c_len;
	for (int i = 0; i < n; i++) {
		ans += x;
		x = (x * x) % m;
	}

	cout << ans << endl;
}