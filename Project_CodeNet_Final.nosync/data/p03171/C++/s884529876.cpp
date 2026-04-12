#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

int N;
int A[3002];
ll dp[3002][3002][2];
ll sagasu(int L, int R, int T) {
	if (dp[L][R][T] != 1e18) return dp[L][R][T];
	if (L > R) dp[L][R][T] = 0;
	else {
		ll a = sagasu(L + 1, R, (T + 1) % 2);
		ll b = sagasu(L, R - 1, (T + 1) % 2);
		if (T) dp[L][R][T] = min(a - A[L], b - A[R]);
		else dp[L][R][T] = max(a + A[L], b + A[R]);
	}
	return dp[L][R][T];
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> N;
	rep1(i, N) cin >> A[i];
	
	rep(i, 3002) rep(j, 3002) rep(k, 2) dp[i][j][k] = 1e18;

	co(sagasu(1, N, 0));

	Would you please return 0;
}