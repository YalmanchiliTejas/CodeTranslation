#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 3e3+10;

pll dp[N][N];
int a[N];

pll rec(int l, int r) {
	if(l==r) {
		return {a[l], 0};
	} else {
		pll f = {0, 0};
		if(dp[l][r] != f) return dp[l][r];
		int x = a[l], y = a[r];
		pll p1 = rec(l+1, r);
		pll p2 = rec(l, r-1);

		swap(p1.first, p1.second);
		swap(p2.first, p2.second);

		p1.first += x;
		p2.first += y;
		pll p = max(p1, p2);
		dp[l][r] = p;
		return p;
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	pll p = rec(0, n-1);
	cout << p.first - p.second;
}