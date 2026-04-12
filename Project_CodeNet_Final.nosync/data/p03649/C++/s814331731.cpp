#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll v[50];
ll eval(ll a, ll b) {
	bool neg = a < 0;
	neg ^= b < 0;
	a = abs(a);
	b = abs(b);
	if (neg)
		return 0;
	return (a + b - 1) / b;
}
bool check(ll m) {
	ll to = m;
	for (ll it = max(0ll, m - 50); it <= to; ++it) {
		m = it;
		ll total = 0;
		for (int i = 0; i < n; ++i) {
			ll need = eval(n - 1 - v[i] - m, -n - 1);
			total += need;
		}
		if (total <= m)
			return true;
	}
	return false;
}
int calc() {
	vector<int> v(::v, ::v + n);
	int res = 0;
	while (true) {
		sort(v.begin(), v.end());
		if (v.back() < n)
			break;
		++res;
		for (int i = 0; i + 1 < v.size(); ++i)
			++v[i];
		v.back() -= n;
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", v + i);
	if (0) {
		for (int i = 0; i < pow(10, n); ++i) {
			if (i%n != 1)
				continue;
			int x = i;
			for (int j = 0; j < n; ++j) {
				v[j] = x % 10;
				x /= 10;
				cout << v[j] << " ";
			}
			cout << "= ";
			cout << calc() << endl;
		}
		return 0;
	}
	//cout << calc() << endl;
	ll l = 0, r = 1e18 + 1, m, res = -1;
	while (l <= r) {
		m = (l + r) / 2;
		if (check(m)) {
			res = m;
			r = m - 1;
		}else
			l = m + 1;
	}
	assert(res != -1);
	printf("%lld\n", res);
	return 0;
}