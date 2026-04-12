#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long a[200020];
long long sum = 0;
int main() {
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum %= 1000000007;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long co = sum - a[i];
		while (co < 0) {
			co += 1000000007;
		}
		ans += a[i] * co;
		ans %= 1000000007;
	}
	long long x = 2;
	n = 1000000005;
	long long ans1 = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans1 = ans1 * x % 1000000007;
		}
		x = x * x % 1000000007;
		n >>= 1;
	}
	ans *= ans1;
	ans %= 1000000007;
	cout << ans << endl;
}
