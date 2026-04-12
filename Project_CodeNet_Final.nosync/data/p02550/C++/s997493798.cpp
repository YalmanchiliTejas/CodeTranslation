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
long long memo[100010] = { 0 }, memo1[100010] = { 0 };
int main() {
	long long n, x, m;
	cin >> n >> x >> m;
	long long ans = x;
	long long loop, loop1;
	bool loop2 = false;
	memo[x] = 1;
	memo1[1] = x;
	for (int i = 2; i <= min(n, m); i++) {
		x *= x;
		x %= m;
		if (memo[x] != 0) {
			loop = ans - memo1[memo[x] - 1];
			loop1 = i - memo[x];
			loop2 = true;
			n -= i - 1;
			break;
		}
		ans += x;
		memo[x] = i;
		memo1[i] = ans;
	}
	if (loop2) {
		ans += loop * (n / loop1);
		for (int i = 0; i < n % loop1; i++) {
			ans += x;
			x *= x;
			x %= m;
		}
	}
	cout << ans << endl;
}
