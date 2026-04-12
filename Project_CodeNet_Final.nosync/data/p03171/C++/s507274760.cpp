#define _CRT_SECURE_NO_WARNINGS
//#include <stdafx.h>
//#include "targetver.h"
#include <stdio.h>
//#include <tchar.h>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif>

#define LL long long
#define MOD 1000000007
#define INF 1000000000
#define LINF 10000000000000000

using namespace std;

const int N = 5e3 + 10;

LL a[N];
LL b[N];
LL pr[N];
LL dp[N][N];
vector<int>vec;
LL n;
LL solve(LL l, LL r) {

	if (l == r)
		return a[l];

	if (dp[l][r] != 0)
		return dp[l][r];

	LL p1 = a[l] + ((pr[r] - pr[l]) - solve(l + 1, r));
	LL p2 = a[r] + ((pr[r - 1] - pr[l-1]) - solve(l, r - 1));
	
	dp[l][r] = max(p1, p2);
	return dp[l][r];
}


int main() {

	scanf("%lld", &n);

	for (int i = 1; i <= n; i++) {

		scanf("%lld", &a[i]);
		pr[i] = pr[i - 1] + a[i];
	}
	LL x = solve(1, n);
	cout << x - (pr[n] - x);

	//cin >> n;
}