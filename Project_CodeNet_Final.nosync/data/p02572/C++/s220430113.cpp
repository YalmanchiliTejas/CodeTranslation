#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <climits>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <complex>
#include <numeric>
#include <chrono>
#include <cmath>
#include <bitset>

using namespace std;

#define FOR(it, ar) for(auto &it: ar)
#define loop(i, start, end) for(auto i = (start); i <= (end); i++)
#define loopSkip(i, start, end, skip) for(auto i = (start); i <= (end); i += skip)
#define loopRev(i, start, end) for(int i = (start); i >= (end); i--)
#define FLASH ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define testCases(t) cin >> t; while(t--)
#define PN(n) cout << (n)
#define PN1(n) cout << (n) << " "
#define PN2(a, b) cout << (a) << " " << (b) << " "
#define PN3(a, b, c) cout << (a) << " " << (b) << " " << (c) << " "
#define PNN1(n) cout << (n) << "\n"
#define PNN2(a, b) cout << (a) << " " << (b) << "\n"
#define PNN3(a, b, c) cout << (a) << " " << (b) << " " << (c) << "\n"
#define PrintObject(ar) for(auto var: ar) cout << var << " "; cout << "\n"
#define PrintMap(map) for(auto var: map) PNN2(var.first, var.second)
#define PrintPair(pair) PNN2(pair.first, pair.second)
#define IN1(n) cin >> n
#define IN2(a, b) cin >> a >> b
#define IN3(a, b, c) cin >> a >> b >> c
#define ALL(s) s.begin(), s.end()
#define ENTER PNN1("")
#define llPair std::pair<lli, lli>
#define iiPair std::pair<int, int>

// Math macros
#define M_PI 3.14159265358979323846

typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

template <typename T>
T ii() {
	T a;
	IN1(a);
	return a;
}

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      // http://xorshift.di.unimi.it/splitmix64.c
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};

int main(void){
	FLASH
	#ifndef ONLINE_JUDGE
		freopen("input-stream.txt", "r", stdin);
		freopen("output-stream.txt", "w", stdout);
	#endif

	int n;
	IN1(n);
	vector<lli> ar(n);
	FOR(it, ar) IN1(it);
	const lli MOD = (lli) 1e9 + 7;
	vector<lli> suffixSum(n, 0);
	suffixSum[n - 1] = ar[n - 1];
	loopRev(i, n - 2, 0) suffixSum[i] = (ar[i] + suffixSum[i + 1]) % MOD;

	lli ans = 0;

	loop(i, 0, n - 1) {
		suffixSum[i] -= ar[i];
		if(suffixSum[i] < 0) suffixSum[i] += MOD;
		ans += (suffixSum[i] * ar[i]) % MOD;
		ans %= MOD;
	}

	PNN1(ans);

	return 0;
}
