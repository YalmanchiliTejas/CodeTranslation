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

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
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

#ifdef __GXX_EXPERIMENTAL_CXX0X__
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
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif


using namespace std;

int main ()
{
	int N;
	while( cin >> N , N )
	{
		vector<vector<int>>data;
		data.resize ( N );
		for( size_t i = 0; i < N; i++ )
		{
			data[i].resize ( N );
		}
		int nowx = N / 2  , nowy = N / 2 + 1;
		data[nowy][nowx] = 1;
		for( size_t i = 2; i <= N*N; i++ )
		{
			nowx++;
			nowy++;
			nowx %= N;
			nowy %= N;
			while( data[nowy][nowx] )
			{
				nowy++;
				nowy %= N;
				nowx--;
				nowx += N;
				nowx %= N;
			}
			data[nowy][nowx] = i;
		}
		for( auto x : data )
		{
			for( auto y : x )
			{
				cout <<setw(4)<<right<< y ;
			}
			cout << endl;
		}
	}
}