#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#define rep(i, n) for (int i = 0; i < (n); i++)
const long long MOD = 1000000007;
using namespace std;
typedef long long ll;
map<ll, int> mp;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (;;) {
		int n;
		cin >> n;
		if (n == 0) return 0;
		int mi = 100000000;
		int ma = 0;
		int sum = 0;
		rep(i, n) {
			int a;
			cin >> a;
			mi = min(a, mi);
			ma = max(a, ma);
			sum += a;
		}
		sum -= (mi + ma);
		cout << sum / (n - 2) << endl;
	}
	return 0;
}
