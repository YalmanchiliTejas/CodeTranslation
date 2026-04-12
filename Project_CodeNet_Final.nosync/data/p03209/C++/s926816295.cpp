#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<time.h>
#include<tuple>
#include<set>
#include<map>
#include<cctype>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
#define tget(a,b) get<a>(b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;
const int MOD = 1e9 + 7;
pair < ll, ll > dp[55];

ll N, K, h[100005];
ll cnt(ll N,ll K) {
	if (N == 1) {
		if (K <= 1) { K = 0; return 0; }
		else { K--; ll unko = K; K = 0; return min(unko, ll(3)); }
	}

	ll ans = 0;
	if (K == 1) { return ans; }
	K--;
	if (K < dp[N - 1].first) {return ans+cnt(N - 1,K); }
	else {
		ans += dp[N - 1].second;
		K -= dp[N - 1].first;
		}
	if (K == 0) return ans;
	K--; ans++;
	if (K == 0) return ans;
	if (K < dp[N - 1].first) { return ans+cnt(N - 1,K); }
	else {
		ans += dp[N - 1].second;
		K -= dp[N - 1].first;
	}
	return ans;
	}

int main(void) {
	dp[1].first = 5; dp[1].second = 3;
	FOR(i, 2, 51) {
		dp[i].first = 2*dp[i - 1].first + 3;
		dp[i].second = 2 * dp[i - 1].second + 1;
	}
	cin >> N>>K;

	ct(cnt(N,K));
	return 0;
}