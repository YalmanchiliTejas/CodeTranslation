#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 998244353

long long int result[3010][3010] = {};

int main() {
	int n, s;
	cin >> n >> s;
	long long int ans = 0;
	int a[3000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	result[0][a[0]] = 1;
	if (a[0] == s) ans += n;
	for (int i = 1; i < n; i++) {
		result[i][a[i]] += i + 1;
		result[i][a[i]] %= mod;
		if (a[i] == s) {
			ans += (i + 1) * (n - i);
			ans %= mod;
		}
		for (int j = 0; j < s; j++) {
			result[i][j] += result[i - 1][j];
			if (j - a[i] >= 0) result[i][j] += result[i - 1][j - a[i]];
			result[i][j] %= mod;
		}
		if (s - a[i] >= 0) {
			ans += (n - i) * result[i - 1][s - a[i]];
			ans %= mod;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j <= s; j++) {
	// 		cout << result[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << ans << endl;
}