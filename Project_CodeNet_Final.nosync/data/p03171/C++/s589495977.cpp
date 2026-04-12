#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e18+5;

ll a[3005];
ll memo[3005][3005];

ll dp(int l, int r) {
	if (l > r) return 0;
	if (memo[l][r] != -INF) return memo[l][r];
	return memo[l][r] = max(a[l] - dp(l+1, r), a[r] - dp(l, r-1));
}

int main() {
	for (int i=0 ; i<3005 ; i++) {
		for (int j=0 ; j<3005 ; j++) {
			memo[i][j] = -INF;
		}
	}
	int n;
	scanf("%d", &n);
	for (int i=0 ; i<n ; i++) {
		scanf("%lld", a+i);
	}
	printf("%lld\n", dp(0, n-1));
	return 0;
}