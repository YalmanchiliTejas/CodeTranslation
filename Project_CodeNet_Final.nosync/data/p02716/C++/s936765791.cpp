#include "bits/stdc++.h"
using namespace std;
// #define endl '\n'
// #define double long double
#define int long long
// int MOD = 1000 * 1000 * 1000 + 7;
// int MOD = 998244353;

int n;
const int MXN = 200005;
int arr[MXN];

bool vis[MXN][3];
int a[MXN][3];

int dp(int atpos, int skipsleft) {
	if (atpos >= n) return 0;
	if (vis[atpos][skipsleft]) return a[atpos][skipsleft];
	vis[atpos][skipsleft] = true;
	if (skipsleft == 0) {
		return a[atpos][skipsleft] = arr[atpos] + dp(atpos+2, 0);
	}
	return a[atpos][skipsleft] = max(
		arr[atpos] + dp(atpos+2, skipsleft),
		dp(atpos+1, skipsleft-1)
	);
}

signed main() {
	
	memset(vis, 0, sizeof vis);
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	
	if (n % 2 == 1) cout << dp(0, 2) << endl;
	else cout << dp(0, 1) << endl;
	
}
