
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;



int main() {
	ll i, n, k; cin >> n >> k;

	ll ans = 0;
	for (i = 1; i <= n; i++) {
		ans += max(0LL, (n/i)*(i - k));
		ans += max(0LL, n%i - k + 1);
	}
	for (i = 1; i <= n; i++) {
		if (0 % i >= k)ans--;
	}

	cout << ans << endl;

	return 0;
}