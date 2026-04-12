#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <math.h>
using namespace std;

//boost
/*
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
*/
/*
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long
#define endl "\n"
#define all(v)  v.begin(),v.end()
#define fir first
#define sec second
#define m_p make_pair
#define m_t make_tuple
#define rep(i,n)  for(int i=0; i<(int) (n); i++)
typedef pair<int, int> P;
typedef long double ld;
typedef long long ll;
template<class T> using PQ_inv = priority_queue<T, vector<T>, greater<T>>;

const double pai = 3.1415926535897;
const ll mod = 1000000007;
const int INF = 1000000021;
const ll LINF = 2000000000000000000;
const int MAX = 510000;
const ll MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];


// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
//n個を1個以上のx組のグループに分ける重複組み合わせはcom(n-1,x-1)
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll PER(int n, int k) {
	if (n < 0 || k < 0) return 0;
	if (n < k) return fac[n];
	return fac[n] * finv[n - k] % mod;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
long long modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}


struct edge {
	int to, cost;
};
edge m_e(int xx, int yy) {
	edge ed;
	ed.to = xx;
	ed.cost = yy;
	return ed;
}
//x未満の要素数を返す二分探索関数
int b_s(vector<int>& vec, int xx) {
	return lower_bound(all(vec), xx) - vec.begin();
}
template<class T>void vecout(vector<T>& vec) { for (T t : vec) cout << t << " "; cout << endl; }
template<class T>void vecin(vector<T>& vec) { for (int i = 0; i < vec.size(); i++) cin >> vec[i]; }
bool chmax(int& xx, int yy) {
	if (xx < yy) {
		xx = yy;
		return true;
	}
	return false;
}
bool chmin(int& xx, int yy) {
	if (xx > yy) {
		xx = yy;
		return true;
	}
	return false;
}
double dist(int x, int y) {
	return sqrt(x * x + y * y);
}
double dist(int xx1, int xx2, int yy1, int yy2) {
	return sqrt(abs(xx1 - xx2) * abs(xx1 - xx2) + abs(yy1 - yy2) * abs(yy1 - yy2));
}
ll mypow(int nn, int kk) {
	ll xx = 1;
	rep(i, kk) {
		xx *= nn;
	}
	return xx;
}
int gcd(int xx, int yy) {
	int p = xx;
	int q = yy;
	if (q > p)swap(p, q);
	while (p % q != 0) {
		p %= q;
		swap(p, q);
	}
	return q;
}
int lcm(int xx, int yy) {
	return xx * yy / gcd(xx, yy);
}
bool prime(int xx) {
	if (xx <= 1) {
		return 0;
	}
	for (int i = 2; i * i <= xx; i++) {
		if (xx % i == 0) {
			return 0;
		}
	}
	return 1;
}



signed main() {
	int n,ans = 0;
	cin >> n;
	vector<int>vec(n),sum(n+1);
	vecin(vec);
	{int t = 0;
		rep(i, n) {
			t += vec[i];
			if (t >= mod)t -= mod;
			sum[i + 1] = t;
		}
	}
	rep(i, n) {
		ans += (vec[i] * sum[i]) % mod;
		if (ans >= mod)ans -= mod;
	}
	cout << ans << endl;
}