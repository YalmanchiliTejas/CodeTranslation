#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <utility>
#include <fstream>

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { a = abs(a), b = abs(b); while (b > 0) { tie(a, b) = make_pair(b, a % b); } return a; }
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
//constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353;
constexpr int MAX = 5000000;


int main()
{

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	ll N, X, M; cin >> N >> X >> M;
	map<ll, ll> mp;
	vector<ll> a(M + 1);
	a[0] = X;
	mp[a[0]] = 0;
	for (ll i = 1; i <= M; i++) {
		a[i] = a[i - 1] * a[i - 1] % M;
		if (mp.find(a[i]) != mp.end()) {
			ll idx = mp[a[i]];
			ll len = i - idx;
			ll sum = 0;
			for (int j = idx; j < i; j++) sum += a[j];
			ll res = 0; for (int j = 0; j < idx; j++) res += a[j];
			N -= idx;
			res += sum * (N / len);
			for (int j = 0; j < N % len; j++) res += a[idx + j];
			cout << res << endl;
			return 0;
		}
		else {
			mp[a[i]] = i;
		}
	}
	ll res = 0; for (int i = 0; i < N; i++) res += a[i];
	cout << res << endl;
	return 0;
}
