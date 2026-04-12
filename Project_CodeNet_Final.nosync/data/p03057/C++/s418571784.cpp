#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

const int mod = 1e9 + 7;

int n, m;
char S[200020];
ll res[200020];
ll D[200020], sum[200020];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", S + 1);
	if(S[1] == 'B') {
		for(int i=1;i<=m;i++) S[i] = (S[i] == 'B' ? 'R' : 'B');
	}
	int all_r = 1;
	for(int i=1;i<=m;i++) if(S[i] != 'R') all_r = 0;
	if(all_r) {
		int dp[200020][2] = {};
		dp[1][0] = 1; dp[1][1] = 0;
		for(int i=2;i<=n;i++) {
			dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
			dp[i][1] = dp[i-1][0];
		}
		int ans = (dp[n][0] + dp[n][1]) % mod;
		memset(dp, 0, sizeof dp);
		dp[1][0] = 0; dp[1][1] = 1;
		for(int i=2;i<=n;i++) {
			dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
			dp[i][1] = dp[i-1][0];
		}
		ans = (ans + dp[n][0]) % mod;
		printf("%d\n", ans);
		return 0;
	}
	while(S[m] == 'R') --m;
	vector <int> v;
	for(int i=1, c=0;i<=m;i++) {
		if(S[i] == 'R') ++c;
		if(S[i] == 'R' && (i == m || S[i+1] == 'B')) {
			v.pb(c);
			c = 0;
		}
	}
	
	if(n % 2) {
		puts("0");
		return 0;
	}
	int lmn = n - 1;
	if(v[0] % 2) lmn = min(lmn, v[0]);
	else lmn = min(lmn, v[0] + 1);
	for(int i=1;i<szz(v);i++) {
		if(v[i] % 2) {
			lmn = min(lmn, v[i]);
		}
	}
	lmn = (lmn + 1) / 2;
	
	int sn = n / 2;
	
	D[0] = sum[0] = 1;
	for(int i=1;i<=sn;i++) {
		D[i] = (sum[i-1] - (i-lmn-1 < 0 ? 0 : sum[i-lmn-1]));
		if(D[i] < 0) D[i] += mod;
		sum[i] = (sum[i-1] + D[i]) % mod;
	}
	
	ll ans = 0;
	for(int i=1;i<=lmn;i++) {
		ans = (ans + (2 * i) * D[sn - i]) % mod;
	}
	printf("%lld\n", ans);
	
	return 0;
}
