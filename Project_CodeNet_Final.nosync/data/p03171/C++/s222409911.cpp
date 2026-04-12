#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>
#include<queue>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int N;
	cin >> N;

	vector<Int> a(N);
	for (Int i = 0; i < N; i++) {
		cin >> a[i];
	}

	vector<vector<Int>> dp(N+1, vector<Int>(N+1));//dp[i][j]:区間[i,j)の局面から出発して双方最善を尽くした時のX-Yの値
	//初期値はdp[i][i]=0;
	
	Int j;
	for (Int len = 1; len < N+1; len++) {
		for (Int i = 0; i+len < N+1; i++) {
			j = i + len;

			//先手の場合
			if (len%2==N%2) {
				dp[i][j] = max(a[i] + dp[i + 1][j], a[j - 1] + dp[i][j - 1]);
			}

			else {
				dp[i][j]=min(-a[i] + dp[i + 1][j], -a[j - 1] + dp[i][j - 1]);
			}
		}
	}

	cout << dp[0][N] << "\n";

}
