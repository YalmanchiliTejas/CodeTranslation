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

Int N;
vector<Int> a;
vector<vector<Int>> dp;



Int solve(Int i, Int j) {
	if (dp[i][j]!=-1) {
		return dp[i][j];
	}

	if (i==j) {
		return dp[i][j] = 0;
	}

	//先手
	if ((j-i)%2==N%2){
		return dp[i][j] = max(a[i] + solve(i + 1, j), a[j - 1] + solve(i, j - 1));
	}

	//後手
	else {
		return dp[i][j] = min(-a[i] + solve(i + 1, j), -a[j - 1] + solve(i, j - 1));
	}
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> N;
	a.resize(N);
	for (Int i = 0; i < N; i++) {
		cin >> a[i];
	}

	dp.resize(N+1);
	for (Int i = 0; i < N+1; i++) {
		dp[i].resize(N + 1,-1);
	}

	cout << solve(0,N) << "\n";

}
