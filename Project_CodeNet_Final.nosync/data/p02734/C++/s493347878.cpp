#pragma GCC target ("avx")
#pragma GCC optimize ("unroll-loops")

#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(998244353);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)

// f(L, R) := 和が S になるように配列 A のいくつかの要素を範囲 [L,R] から選ぶ選び方
// 左端の選ぶ値を固定して dp
// 右端に到達したときに 1 ではなく N-R を加算

int N, S;
int A[3000];

ll dp[3000][3000];
ll solve(int n, int s){
	if(s > S) return 0;
	if(s == S) return N-n+1;
	if(n == N) return 0;
	if(dp[n][s] != -1) return dp[n][s];
	return dp[n][s] = (solve(n+1, s)+solve(n+1, s+A[n]))%MOD;
}

signed main(){
	scanf("%d%d", &N, &S);
	rep(i, N) scanf("%d", A+i);

	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	rep(i, N){
		ans += solve(i+1, A[i])*(i+1);
		ans %= MOD;
	}
	printf("%lld\n", ans);
}