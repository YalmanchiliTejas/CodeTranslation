#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
using namespace std;

typedef long long ll;
#define modulo 1000000007 // 10^9 + 7
#define MAX 1000000000 // 10^9

ll L[55], P[55];

ll ans(ll n, ll x) {
	if (n == 0) return 1;
	else if (x == 1) return 0;
	else if (x <= L[n-1] + 1) return ans(n - 1, x - 1);
	else if (x == L[n-1] + 2) return P[n-1] + 1;
	else return ans(n - 1, x - L[n-1] - 2) + P[n-1] + 1;
}


int main() {
	ll n, x; cin >> n >> x;
	L[0] = P[0] = 1;
	for (int i = 1; i < 55; i++) {
		L[i] = 2 * L[i - 1] + 3;
		P[i] = 2 * P[i - 1] + 1;
	}
	cout << ans(n, x) << endl;

	return 0;
}