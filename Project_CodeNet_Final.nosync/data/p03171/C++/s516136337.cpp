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

const int N = 2e6 + 10;

LL a[N];
LL b[N];
LL pr[N];
LL dp[3005][3005];
vector<int>vec;

int main() {

	LL n;
	scanf("%lld", &n);

	for (LL i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	//dp[n - 1][n - 1] = a[n - 1];
	for (LL L = n - 1; L >= 0; L--)
		for (LL R = L; R < n; R++) {
			
			if (L == R)
				dp[L][R] = a[L];
			else
				dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
			
		}
	printf("%lld\n", dp[0][n - 1]);
	//cin >> n;
}