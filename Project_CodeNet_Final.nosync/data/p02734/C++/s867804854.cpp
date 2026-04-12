#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 998244353
#define INF2 1000000000000000000
#define int long long
int A[3010];
#define int long long 
int F[2100010];

int Mul(int a, int b) {
	return ((a % mod) * (b % mod)) % mod;
}

void fact(void) {
	F[0] = 1;
	F[1] = 1;
	for (int i = 2; i <= 2100000; i++) {
		F[i] = Mul(i, F[i - 1]);
	}
}
int square(int x) {
	return (x * x) % mod;
}

int power(int x, int y) {
	if (y == 0) return 1;
	else if (y == 1) return x % mod;
	else if (y % 2 == 0) return square(power(x, y / 2)) % mod;
	else return square(power(x, y / 2)) * x % mod;
}

int Div(int a, int b) {
	return Mul(a, power(b, mod - 2));
}
int P(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return Div(F[n], F[n - r]);
}

int C(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	int ret;
	ret = Div(F[n], Mul(F[n - r], F[r]));
	return ret;
}
int H(int n, int r) {
	if (n == 0 && r == 0) return 1;
	return C(n + r - 1, r);
}
int dp[3010][3010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, S;
    cin >> N >> S;
    rep(i, N) cin >> A[i];
    int ans = 0;
    rep(i, 3010) rep(j, 3010) dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i, N) {
        REP(j, 0, S) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            if(j == 0) dp[i + 1][j]++;
            if (j - A[i] >= 0) 
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - A[i]]) % mod;
        }
    }
    rep(i, N + 1) {
        ans = (ans + dp[i][S]) % mod;
    }
    cout << ans << endl;


    return 0;
}
