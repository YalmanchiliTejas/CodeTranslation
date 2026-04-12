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
 size_t strlen(const char *s);
#define rep(i,n) for(long long int i=0;i<n;i++)
#define sz(x) ((int)(x).size())

using namespace std;
struct ToUpper {
    char operator()(char c) { return toupper(c); }
};
struct ToLower {
    char operator()(char c) { return tolower(c); }
};
const int N=200010;
const int P=1000000007;
using ll = long long;

//絶対値
int ze(int a, int b){
	if(a>b){
		return a-b;
	}else{
		return b-a;
	}
}
//小さい方
long long int min(long long int a,long long int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}
//大きい方
long long int max(long long int a,long long int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
// a^n mod 
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod 
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

//mod掛け算
long long mt(long long a, long long b, long long mod){
	return (a*b)%mod;
}

//メモ

/*
	memset(b, '\0', sizeof(b));
初期化*/

/*
	char s[N];
	strlen(s)
*/

/*
	if(  <  )puts("Yes");
	else puts("No");
*/

/*文字列比較
if(strcmp(name[i],s)==0)
*/

/*
	graph[a].push_back(b);//graph[a][i番目に入れた]==b
	graph[j].size()	//forで回すときとか

*/

/*添字1がa個、2がb個
  vector<vector<ll>> map(a,vector<ll>(b));
*/

int main(){
  ll x;
  cin>>x;
  	if(  x>=30  )puts("Yes");
	else puts("No");
}
    