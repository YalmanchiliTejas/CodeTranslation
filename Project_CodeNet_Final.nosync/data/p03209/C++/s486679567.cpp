//include,using,define等
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>

// ===============================================================
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
using ui = unsigned int;
using qul = queue<ll>;
using pql = priority_queue<ll>;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#pragma region header
//#define int long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define INF (ll)10000000000000000
#define mod (ll)1000000007
#define P pair<lint,lint>
template <class T>
bool chmax(T & a, const T & b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
template <class T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion
lint n, x;
lint pat[55];
lint bag[55];
void r() {
	pat[0] = 1;
	bag[0] = 1;
	for (int i = 1; i < 52; i++) {
		bag[i] = bag[i - 1] * 2 + 3;
		pat[i] = pat[i - 1] * 2 + 1;
	}
	return;
}
lint solve(lint a, lint b) {
	if (a == 1 && b == 2)
		return 1;

	if (a == 1 && b == 3)
		return 2;

	if (a == 1 && b == 4)
		return 3;

	if (a == 1 && b == 5)
		return 3;

	if (b == 1) 
		return 0;
	
	if (b <= 1 + bag[a - 1]) 
		return solve(a - 1, b - 1);
	
	if (b == 2 + bag[a - 1]) 
		return pat[a - 1] + 1;
	
	if (b <= 2 + bag[a - 1] * 2) 
		return pat[a - 1] + 1 + solve(a - 1, b - 2 - bag[a - 1]);
	
	if (b == 3 + bag[a - 1] * 2)
		return pat[a];
	
}


int main(void) {
	cin >> n >> x;
	r();
	printf("%lld\n", solve(n, x));

	return 0;
}