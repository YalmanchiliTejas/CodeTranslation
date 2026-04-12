#define _USE_MATH_DEFINES
#pragma region include

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
#pragma endregion //#include
/////////

#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
//////////////

void solve() {
	const LL P = 998244353;
	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	/*
	dp[i][j]
	A_iまで見たときに
	合計がjになる場合の数。
	更新A_(i+1)で更新される
	dp[i+1][j] += dp[i][j] mod
	dp[i+1][j+A_(i+1)] += dp[i][j] mod
	*/
	vector<vector<LL>> dp(N+1, vector<LL>(S+1,0));
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		//A[i]
		LL ter = A[i];
		dp[i + 1][0] = 1;
		if (ter == S) {
			dp[i + 1][ter] = ((i + 1) * (N - i)) % P;
		}
		else if (ter < S) {
			dp[i + 1][0 + ter] = (i + 1) % P;
		}

		for (int s = 1; s < S; ++s) {
			dp[i + 1][s] += dp[i][s];
			dp[i + 1][s] %= P;
			LL wa = s + A[i];
			if (wa == S) {
				LL res = (dp[i][s] * (N - i)) % P;
				dp[i + 1][wa] += res;
				dp[i + 1][wa] %= P;
			}
			else if(wa<S){
				dp[i + 1][wa] += dp[i][s];
				dp[i + 1][wa] %= P;
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i <= N; ++i) {
		ans += dp[i][S];
		ans %= P;
	}
	cout << ans << endl;
}

#pragma region main
signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
