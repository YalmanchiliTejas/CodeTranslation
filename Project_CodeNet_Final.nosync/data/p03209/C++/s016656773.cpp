#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;
typedef long long signed int ll;

constexpr int inf = INT32_MAX / 2;
constexpr int mod = 1000000007;
constexpr int maxn = 100000;

ll layer(ll n) {
	if (n == 0) return 1;
	return layer(n - 1) * 2 + 3;
}

ll patty(ll n) {
	if (n == 0) return 1;
	return patty(n - 1) * 2 + 1;
}

ll solve(ll n, ll x) {
	if (x <= 1) return 0;
	else if (x < 1 + layer(n - 1)) return solve(n - 1, x - 1);
	else if (x == 1 + layer(n - 1)) return patty(n - 1);
	else if (x == 1 + layer(n - 1) + 1) return patty(n - 1) + 1;
	else if (x < 1 + layer(n - 1) + 1 + layer(n - 1)) return patty(n - 1) + 1 + solve(n - 1, x - (1 + layer(n - 1) + 1));
	else if (x == 1 + layer(n - 1) + 1 + layer(n - 1)) return patty(n - 1) + 1 + patty(n - 1);
	else if(x == 1 + layer(n-1)+1+layer(n-1)+1)return patty(n - 1) + 1 + patty(n - 1);
	else throw;
}

int main() {
	ll n, x;
	cin >> n >> x;
	cout << solve(n, x) << endl;
}
