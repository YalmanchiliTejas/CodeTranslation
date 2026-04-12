#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,s,t) for (int i = s; i < t; ++i)

const int N = 2e5;
int n, a[N];
ll sum0[N+1], sum1[N+1];

int main() {
	cin >> n;
	rep(i,n) {
		cin >> a[i];
		sum0[i+1] = sum0[i];
		sum1[i+1] = sum1[i];
		if (i%2) sum1[i+1] += a[i];
		else sum0[i+1] += a[i];
	}

	ll ans = LLONG_MIN, mx = LLONG_MIN;
	if (n%2) {
		for (int i=n-1; i>=0; i-=2) {
			mx = max(mx, sum1[i]+sum0[n]-sum0[i+1]);
			ans = max(ans, sum0[i]+mx-sum1[i]);
		}
	}
	else {
		for (int i=n; i>=0; i-=2) {
			ans = max(ans, sum0[i]+sum1[n]-sum1[i]);
		}
	}

	printf("%lld\n", ans);
}