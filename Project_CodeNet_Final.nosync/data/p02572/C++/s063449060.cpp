#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <list>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define xx first
#define yy second
#define $1 first
#define $2 second

const ll MOD = 1e9 + 7;

void solveCase() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n; cin >> n;
	ll ans = 0;
	vector<ll> a; a.resize(n);
	for (int i = 0; i < n; i++) cin >>a[i];
	vector<ll> prefix; prefix.resize(n); prefix[0] = a[0]%MOD;
	for (int i = 1; i < n; i++) {
		prefix[i] = (a[i] + prefix[i - 1])%MOD;
	}

	for (int i = 0; i < n-1; i++) {
		ans += ((a[i] % MOD) * (prefix[n - 1] - prefix[i] + MOD) % MOD) % MOD;
	}
	ans %= MOD;
	cout << ans;

}


int main() {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	solveCase();
}