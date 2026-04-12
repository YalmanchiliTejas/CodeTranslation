//#define NDEBUG
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
static constexpr double PI = 3.1415926535897932;

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;

	template <typename T>
	auto scan(T &d) ->
		typename std::enable_if<std::is_same<T, std::string>::value>::type {
		d = std::string();
		int c = 0;
		while (c < 'a' || 'z' < c)
			c = fgetc(stdin);
		while ('a' <= c && c <= 'z') {
			d.push_back(c);
			c = fgetc(stdin);
		}
	}
	template <typename T>
	auto scan(T &d) ->
		typename std::enable_if<std::is_same<T, double>::value>::type {
		scanf("%lf", &d);
	}
	template <typename T>
	auto scan(T &d) ->
		typename std::enable_if<std::is_signed<T>::value ==
		std::is_same<T, std::string>::value>::type {
		d = 0;
		int c = 0;
		while (c < '0' || '9' < c)
			c = fgetc(stdin);
		while ('0' <= c && c <= '9') {
			d = d * 10 + c - '0';
			c = fgetc(stdin);
		}
	}
	template <typename T>
	auto scan(T &d) ->
		typename std::enable_if<std::is_signed<T>::value !=
		std::is_same<T, double>::value>::type {
		d = 0;
		int c = 0;
		bool f = 0;
		while (c < '0' || '9' < c) {
			if (c == '-')
				f = 1;
			c = fgetc(stdin);
		}
		while ('0' <= c && c <= '9') {
			d = d * 10 + c - '0';
			c = fgetc(stdin);
		}
		if (f)
			d = -d;
	}

int main(void)
{
	uint32 n, k;
	scan(n);scan(k);
	++n;
	uint64 ans = 0;
	for (uint32 i = k + 1;i < n;++i) {
		ans += (i - k)*(n / i);
		if (n%i >= k) {
			ans += n%i - k;
		}
	}
	if (k == 0) ans -= n - 1;
	printf("%lu\n", ans);
	return 0;
}