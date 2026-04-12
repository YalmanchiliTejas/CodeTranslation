#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
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

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

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
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define reps(i, j, k) for(auto i = j; i < k; ++i)
#define rep(i, j) reps(i, 0, j)
#define decs(i, j, k) for(auto i = j; i >= k; --i)
#define dec(i, j) decs(i, j, 0)
#define iter(i, j) for(auto i = j.begin(); i != j.end(); ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define vpi vector<pi>
#define vb vector<bool>
#define F first
#define S second
#define mp make_pair
#define um unordered_map
#define all(x) (x).begin(), (x).end()  
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
#define file_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define IMAX std::numeric_limits<int>::max()
#define IMIN std::numeric_limits<int>::min()
using namespace std;

int main()
{
    //fast_io
    //file_io
	string s; cin >> s;
	string ans = "No";
	reps(i, 1, s.length())
	{
		if(s[i] != s[0]) 
		{
			ans = "Yes";
			break;
		}
	}
	cout << ans;
}
