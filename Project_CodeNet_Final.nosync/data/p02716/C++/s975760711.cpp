#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = (int)2e5 + 5;

int n;
ll dat[N];
ll dp1[N], dp2[N][2];

ll DP1(int cur) {
	if (cur >= n) return 0;
	ll& ret = dp1[cur];
	if (ret != -1) return ret;
	if (cur % 2 == 0) {
		ret = dat[cur] + max(DP1(cur+2), DP1(cur+3));
	}
	else {
		ret = dat[cur] + DP1(cur+2);
	}
	return ret;
}

ll DP2(int cur, int stat) {
	if (cur >= n) return 0;
	ll& ret = dp2[cur][stat];
	if (ret != -1) return ret;
	if (cur % 2 == 0) {
		if (stat == 0) {
			ll opt1 = DP2(cur+2, stat);
			ll opt2 = DP2(cur+3, stat);
			ll opt3 = DP2(cur+4, 1);
			ret = dat[cur] + max(opt1, max(opt2, opt3));
		}
		else {
			ret = dat[cur] + DP2(cur+2, stat);
		}
	}
	else {
		ll opt1 = DP2(cur+2, stat);
		ll opt2 = DP2(cur+3, 1);
		ret = dat[cur] + max(opt1, opt2);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &dat[i]);
	reset(dp1,-1);
	reset(dp2,-1);
	if (n % 2 == 0) {
		printf("%lld\n", max(DP1(0), DP1(1)));
	}
	else {
		printf("%lld\n", max(DP2(2,1), max(DP2(0,0), DP2(1,0))));
	}
	return 0;
}