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
const long long MOD = 1e9 + 7;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned long long ULL;
//typedef boost::multiprecision::cpp_int bigint;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	LL N;
	cin >> N;
	VLL A(N);
	for (LL n = 0; n < N; n++) {
		cin >> A[n];
	}
	if (N == 2) {
		cout << max(A[0], A[1]) << "\n";
		return 0;
	}
	VLL sum(N,0);
	sum[0] = A[0];
	for (LL n = 2; n < N; n += 2) {
		sum[n] = sum[n - 2] + A[n];
	}
	VLL DP(N);
	DP[0] = 0;
	DP[1] = max(A[0], A[1]);
	DP[2] = max(A[0], max(A[1], A[2]));
	for (LL n = 3; n < N; n++) {
		if (n & 1) {
			DP[n] = DP[n - 2] + A[n];
			DP[n] = max(DP[n], sum[n-1]);
		}
		else {
			DP[n] = DP[n - 2] + A[n];
			DP[n] = max(DP[n], DP[n-3] + A[n - 1]);
			DP[n] = max(DP[n], sum[n - 2]);
		}
	}
	cout << DP[N-1] << "\n";
	return 0;
}
