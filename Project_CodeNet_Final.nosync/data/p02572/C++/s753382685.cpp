#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>
#include <cassert>

using ll = long long;
using ull = unsigned long long;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

constexpr ll NOT_SPECIFIED_VALUE_MIN = INT64_MIN;
constexpr ll NOT_SPECIFIED_VALUE_MAX = INT64_MAX;

template <typename T>
T extGCD(T a, T b, T &x, T &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	T d = extGCD(b, a%b, y, x); // 再帰的に解く
	y -= a / b * x;
	return d;
}

// 負の数にも対応した mod 
template <typename T>
T modG(T a, T m) {
	return (a % m + m) % m;
}

// 逆元計算 
template <typename T>
T modinv(T a, T m) {
	T x, y;
	extGCD(a, m, x, y);
	return modG(x, m);
}


int main()
{
	ll sum = 0;
	ll n;
	cin >> n;
	vector<ll> v( n );
	for( ll i = 0; i < n; i++ )
	{
		cin >> v[i];
		sum += v[i];
		sum %= mop;
	}

	ll ans = 0;
	for(ll i=0;i<n;i++){
		ans += ( v[i] * modG( sum - v[i], mop ) ) % mop;
		ans %= mop;
	}
	
	cout << (ans * modinv(2LL, mop)) % mop << endl;


}
