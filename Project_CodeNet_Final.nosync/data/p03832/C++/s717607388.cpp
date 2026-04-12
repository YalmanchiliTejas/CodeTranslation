#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<cmath>
#include<unordered_set>
#define int long long
#define mod 1000000007
using namespace std;

int dp[1001][1001];//i人以下のグループを使ってj人をグループにした
vector<int>C[1001];//i人からj人選ぶ方法
int p(int a, int b) {
	int c = 1;
	while (b > 1) {
		if (b & 1)c = c*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return a*c%mod;
}
signed main() {
	C[0].push_back(1);
	for (int i = 1; i <= 1000; i++) {
		C[i].push_back(1);
		for (int j = 1; j < i; j++) {
			C[i].push_back((C[i - 1][j - 1] + C[i - 1][j])%mod);
		}
		C[i].push_back(1);
	}
	int N, a, b, c, d; cin >> N >> a >> b >> c >> d;
	dp[a - 1][0] = 1;
	for (int i = a; i <= b; i++) {//i人のグループを使う
		for (int j = 0; j <= N; j++) {//j人をグループにした
			int n = 1, m = 1;
			for (int k = 0; k <= (N - j) / i; k++) {
				if (k) {
					n *= C[N - j - i*(k - 1)][i]; n %= mod;
					m *= k; m %= mod;
				}
				if (k == 0 || (k >= c&&k <= d)) {
					dp[i][j + i*k] = (dp[i][j + i*k] + dp[i - 1][j]*n%mod*p(m,mod-2)) % mod;
				}
			}
		}
	}
	cout << dp[b][N] << endl;
}