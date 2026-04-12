#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int mod = 1000000007;
int n;
int a[200000];

signed main() {
	int i;
	
	cin >> n;
	rep(i, n) cin >> a[i];
	
	int sumA = 0;
	rep(i, n) { sumA += a[i]; }
	
	int ans = 0;
	rep(i, n) {
		sumA -= a[i];
		
		ans += a[i] * (sumA % mod);
		ans %= mod;
	}
	
	cout << ans << endl;
	return 0;
}