/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
			　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#endif
#define rep(i, n) for(Int (i) = 0; (i) < (n); ++(i))
#define all(n) std::begin(n), std::end(n)
#define rall(n) std::rbegin(n), std::rend(n)
#define debug(var) std::cout << #var << ": " << var << "\n"
using Int = int64_t;
constexpr Int INF = INT_MAX;
constexpr Int mod = 1e9 + 7;


void init() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
}

void calc() {

	std::string S; std::cin >> S;
	Int N = S.size(); //桁数
	Int K = 0; std::cin >> K;

	std::vector<std::vector<std::array<Int, 2>>> dp(N + 1, std::vector<std::array<Int, 2>>(K + 1));
	dp[0][0][0] = 1;
	
	rep(i, N)rep(j, K + 1)rep(k, 2) {
		Int nd = (Int)(S[i] - '0');
		rep(d, 10) {
			//次の遷移先を決める
			Int ni = i + 1, nj = j, nk = k;
			if (d != 0)nj++;
			if (nj > K)continue;
			if (k == 0) {
				if (d > nd)continue;
				if (d < nd)nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}

	Int ans = dp[N][K][0] + dp[N][K][1];
	std::cout << ans;

}


int main() {

	init();
	calc();

	return 0;
}