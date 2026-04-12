#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
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
#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
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

using namespace std;

using llong = long long;
using ullong = unsigned long long;

#ifndef __MACRO_H__
#define __MACRO_H__

#define all(collection)  (collection).begin(), (collection).end()
#define loop(i, times) for (llong i = 0; i < times; i++)
#define rloop(i, times) for (llong i = times -1; 0 <= i; i--)

std::chrono::system_clock::time_point  start;

void TimeStart(void)
{
	start = std::chrono::system_clock::now();
}

void TimeEnd(void)
{
	auto time = std::chrono::system_clock::now() - start;
	auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
	cerr << endl << msec << " msec " << endl;
}

#endif


int main(void)
{
	llong n; cin >> n;
	vector<llong> h;
	llong ans = 0;

	h.resize(n);
	loop(i, n)
	{
		cin >> h[i];
	}

	llong h_max = h[0];
	loop(i, n)
	{
		if (h[i] < h_max)
			ans++;

		h_max = max(h[i], h_max);
	}

	cout << n-ans;
	return 0;
}