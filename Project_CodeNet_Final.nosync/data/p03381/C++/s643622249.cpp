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
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
constexpr double PI = 3.1415926535897932;

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;

const char *yes(bool c) { return c ? "yes" : "no"; }
const char *Yes(bool c) { return c ? "Yes" : "No"; }
const char *YES(bool c) { return c ? "YES" : "NO"; }
const char *pos(bool c) { return c ? "possible" : "impossible"; }
const char *Pos(bool c) { return c ? "Possible" : "Impossible"; }
const char *POS(bool c) { return c ? "POSSIBLE" : "IMPOSSIBLE"; }
template<class T>bool bmaxi(T&a, const T&b) { if (b<a)return 0;a = b;return 1; }
template<class T>bool bmini(T&a, const T&b) { if (a<b)return 0;a = b;return 1; }
template<class T>bool nmaxi(T&a, const T&b) { if (a<b) { a = b;return 1; }return 0; }
template<class T>bool nmini(T&a, const T&b) { if (b<a) { a = b;return 1; }return 0; }
template<typename T>auto scan(T&d)->typename std::enable_if<std::is_signed<T>::value>::type
{
	d = 0;int c = fgetc(stdin);bool f = 0;while (c<'0' || '9'<c) { if (c == '-')f = 1;c = fgetc(stdin); }
	while (c != ' '&&c != '\n') { d = d * 10 + c - '0';c = fgetc(stdin); }if (f)d = -d;
}
template<typename T>auto scan(T&d)->typename std::enable_if<!std::is_signed<T>::value>::type
{
	d = 0;int c = fgetc(stdin);while (c == ' ' || c == '\n')c = fgetc(stdin);
	while (c != ' '&&c != '\n') { d = d * 10 + c - '0';c = fgetc(stdin); }
}
void scan(char&d) { d = fgetc(stdin);while (d == ' ' || d == '\n')d = fgetc(stdin); }
void scan(double&d) { scanf("%lf", &d); }void scan(std::string&d) {
	d.clear();int c = fgetc(stdin);
	while (c == ' ' || c == '\n')c = fgetc(stdin);while (c != ' '&&c != '\n') { d.push_back(c);c = fgetc(stdin); }
}
template<typename F, typename...R>void scan(F&f, R&...r) { scan(f);scan(r...); }
template<typename T>T input() { T d;scan(d);return d; }
template <typename T>auto print(T d)->typename std::enable_if<std::is_signed<T>::value>::type
{
	static int c[20];int i = 0;bool f = 0;if (d<0) { f = 1;d = -d; }while (d) { c[i++] = d % 10;d /= 10; }
	if (!i)c[i++] = 0;if (f)fputc('-', stdout);while (i--)fputc(c[i] + '0', stdout);
}
template<typename T>auto print(T d)->typename std::enable_if<!std::is_signed<T>::value>::type
{
	static int c[20];int i = 0;while (d) { c[i++] = d % 10;d /= 10; }
	if (!i)c[i++] = 0;while (i--)fputc(c[i] + '0', stdout);
}
template<>void print<char>(char d) { fputc(d, stdout); }
template<>void print<double>(double d) { printf("%f", d); }
void print(const char *c) { while (*c != '\0')fputc(*(c++), stdout); }void print() {}
template<typename F, typename...R>void print(F f, R...r) { print(f);print(r...); }
template<typename...R>void println(R...r) { print(r...);fputc('\n', stdout); }
template<typename...R>int END(R...r) { println(r...);return 0; }

int main(void) {
	uint32 n;
	scan(n);
	std::vector<std::pair<uint32, uint32>> a(n);
	for (auto &e : a)scan(e.first);
	for (uint32 i = 0;i < n;++i)a[i].second = i;
	std::sort(a.begin(), a.end());
	std::vector<uint32> ans(n);
	for (uint32 i = 0;i < n / 2;++i) {
		ans[a[i].second] = a[n / 2].first;
	}
	for (uint32 i = n / 2;i < n;++i) {
		ans[a[i].second] = a[n / 2-1].first;
	}
	for (const auto e : ans) {
		println(e);
	}
	return 0;
}