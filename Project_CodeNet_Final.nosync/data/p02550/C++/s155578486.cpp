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
#include <numeric>

//#include "atcoder/segtree.hpp"
using namespace std;

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
#define ALL(v)  v.begin(),v.end()
#define m_p make_pair
#define m_t make_tuple
#define rep(i,n)  for(int i=0; i<(int) (n); i++)
typedef pair<int, int> P;
typedef long double ld;
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<vector<char>> VVC;
template<class T> using PQ_inv = priority_queue<T, vector<T>, greater<T>>;

const double pai = 3.1415926535897;
/*const*/ ll mod = 1000000007;
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
long long fix_mod(int &xx) {
	if (xx >= mod * 2||xx<-mod*2) {
		xx %= mod;
	}
	if (xx >= mod)xx -= mod;
	//if (xx < 0)xx += mod;
	return xx;
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
	return lower_bound(ALL(vec), xx) - vec.begin();
}
template<class T>void vecout(vector<T>& vec) { for (T t : vec) cout << t << " "; cout << endl; }
template<class T>void vecout(vector<vector<T>>& vec) {for (vector<T>tvec : vec) {for (T t : tvec)cout << t << " "; cout << endl;}}
template<class T>void vecout(vector<pair<T, T>>& vec) {for (pair<T, T>p : vec) {cout << p.first << " " << p.second << endl;}}
template<class T>void vecin(vector<T>& vec) { for (int i = 0; i < (int)vec.size(); i++) cin >> vec[i]; }
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
template<class T>
double dist(T x, T y) {
	return sqrt(x * x + y * y);
}
template<class T>
double dist(T xx1, T yy1, T xx2, T yy2) {//1つ目x座標,1つ目y座標,2つ目x座標,2つ目y座標
	return sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
}
template<class T>
double dist(pair<T,T> p1, pair<T,T> p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
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
int lcm(int xx, int yy) {return (xx / gcd(xx, yy)) * yy;}
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

int op(int xx) {
	return (xx * xx) % mod;
}
struct kyopro_friends {
	int before_loop,loop_size, loop_sum;
	VI vec;//i回目の操作後のsumを格納 (1-indexed)
	map<int, int>corresp;//keyが最初に出てくる場所 (1-indexed)
	kyopro_friends(int xx) {
		vec = { 0,xx };
		corresp[xx] = 1;
		int sum=xx,cnt = 1,a=xx;
		while (1) {
			a = op(a);
			cnt++;
			sum += a;
			vec.push_back(sum);
			if (corresp.count(a)) {
				loop_size = cnt - corresp[a];
				loop_sum = sum - vec[corresp[a]];
				before_loop = corresp[a];
				break;
			}
			corresp[a] = cnt;
		}
	}
	int get_element(int xx) {
		int a = (xx - before_loop) % loop_size + before_loop;
		return vec[a] - vec[a - 1];
	}
	int get_sum(int xx) {
		return (xx - before_loop) / loop_size * loop_sum + vec[(xx - before_loop) % loop_size + before_loop];
	}
};


signed main() {
	int n, x, m;
	cin >> n >> x >> m;
	mod = m;
	kyopro_friends kyo(x);
	cout << kyo.get_sum(n) << endl;
}
