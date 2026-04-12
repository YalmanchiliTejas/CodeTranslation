#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 998244353;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N, S;
	cin >> N >> S;
	VI A(N);
	for (int n = 0; n < N; n++)cin >> A[n];
	VVLL DP;
	DP.resize(N, VLL(3001, 0));
	if(A[0] <= 3000)DP[0][A[0]] = 1;
	for(int r = 1;r < N;r++){
		for (int s = 0; s <= 3000; s++) {
			DP[r][s] = DP[r - 1][s];
			if (s >= A[r]) {
				DP[r][s] += DP[r - 1][s - A[r]];
			}
			if (s == A[r])DP[r][s] += r + 1;
			DP[r][s] %= MOD;
		}
	}
	LL ans = 0;
	if (A[0] == S)ans += N;
	for (int r = 1; r < N; r++) {
		if (S >= A[r]) {
			ans += DP[r - 1][S - A[r]]*(N-r);
			ans %= MOD;
		}
		if (S == A[r]) {
			ans += (N - r) * (r + 1);
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}
