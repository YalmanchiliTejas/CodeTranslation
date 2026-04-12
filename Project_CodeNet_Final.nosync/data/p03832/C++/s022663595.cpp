#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> H >> W >> L >> R;
	vector<long long int>pow(1001);
	vector<long long int>div(1001);
	pow[1] = 1;
	pow[0] = 1;
	div[0] = 1;
	for (int i = 2; i < 1001; i++) {
		pow[i] = pow[i - 1] * i;
		pow[i] %= MOD;
	}
	for (int i = 1; i <= 1000; i++) {
		div[i] = power(pow[i], MOD - 2, MOD);
	}
	vector<vector<long long int>>dp(1001, vector<long long int>(1001, 0));
	for (int i = 0; i <= 1000; i++) {
		dp[i][0] = 1;
	}
	for (int i = H; i <= W; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = L*i; k <= R*i; k += i) {
				if (j < k)break;
				long long int box = dp[i - 1][j - k];
				box *= pow[N - j + k];
				box %= MOD;
				box *= div[N - j];
				box %= MOD;
				box *= power(div[i], k / i, MOD);
				box %= MOD;
				box *= div[k / i];
				box %= MOD;
				dp[i][j] += box;
			}
			dp[i][j] %= MOD;
		}
	}
	cout << dp[W][N] << endl;
	return 0;
}
