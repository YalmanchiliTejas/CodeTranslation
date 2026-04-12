#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int MOD = (ll)1000000000 + 7;
ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
const int MAX = 500050;
typedef pair<int, int>P;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long power_mod(long long x, long long n, long long m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return power_mod(x * x % m, n / 2, m);
	else
		return x * power_mod(x, n - 1, m) % m;
}
//n人からk人組をx個
ll func(int n, int k, int x) {
	return COM(n, k * x)* fac[k * x] % MOD* power_mod(finv[k], x, MOD) % MOD*finv[x]%MOD;
}

int dp[1010][1010];
signed main() {
	int N, A, B, C, D; 
	cin >> N >> A >> B >> C >> D;
	REP(i, 1010) {
		dp[i][0] = 1;
	}
	COMinit();
	for(int k = 1; k <= N; k++) {
		REP(n, N + 1) {
			ll res = 0;
			if (A <= k && k <= B) {
				res += func(n, k, 0) * dp[k - 1][n];
				FOR(x, C, D + 1) {
					if (n-k*x<0)break;
					res += func(n, k, x) * dp[k - 1][n - k * x]%MOD;
					res %= MOD;
				}
			}
			else {
				res += func(n, k, 0) * dp[k - 1][n];
			}
			dp[k][n] = res;
		}
	}
	/*REP(i, N + 1) {
		REP(j, N + 1) {
			pe(i)pe(j); print(dp[i][j]);
		}
	}*/
	print(dp[N][N]);
	/*while (true) {
		int n, k, x; cin >> n >> k >> x;
		print(func(n, k, x));
	}*/
}