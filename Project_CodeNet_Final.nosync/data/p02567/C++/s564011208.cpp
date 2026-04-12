#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

#include <atcoder/dsu.hpp>
#include <atcoder/fenwicktree.hpp>
#include <atcoder/segtree.hpp>

using namespace std;
using namespace atcoder;

typedef long long ll;
#define unionFind dsu

#define endl '\n'

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}

///////////////   セグメント木

// ここでセグ木の設定をする

// #define SEGTREE_DATA_ADD			// 和をとるセグ木
#define SEGTREE_DATA_MAX			// 最大値をとるセグ木
// #define SEGTREE_DATA_MIN			// 最小値をとるセグ木

// #define SEGTREE_LAZY_SET			// 区間代入する遅延セグ木
// #define SEGTREE_LAZY_ADD			// 区間加算する遅延セグ木
// #define SEGTREE_LAZY_MAX			// 最大値を更新する遅延セグ木
// #define SEGTREE_LAZY_MIN			// 最小値を更新する遅延セグ木


const ll INF = 1LL << 60;
#ifdef SEGTREE_DATA_ADD
const ll segtree_data_init_value = 0;
inline ll segtree_data_merge(ll a, ll b) {// 要素aのbの和
	return a + b;
}
#endif
#ifdef SEGTREE_DATA_MAX
const ll segtree_data_init_value = -INF;
inline ll segtree_data_merge(ll a, ll b) {// 要素aのbの最大値
	return max(a, b);
}
#endif
#ifdef SEGTREE_DATA_MIN
const ll segtree_data_init_value = INF;
inline ll segtree_data_merge(ll a, ll b) {// 要素aのbの最小値
	return min(a, b);
}
#endif
ll segtree_data_init() { return segtree_data_init_value; }

#ifdef SEGTREE_LAZY_SET
const ll segtree_lazy_init = 0;
inline ll segtree_lazy_merge(ll a, ll b) {// 演算子aとbのマージ
	return b;
}
inline ll segtree_lazy_multi(ll a, ll n) {// 演算子aをn個つなげたもの
	return a;
}
inline ll segtree_lazy_divide(ll a) {// 演算子aを二個に分ける
	return a;
}
inline ll segtree_lazy_apply(ll a, ll x) {// aに演算子xを適用する
	return x;
}
#endif
#ifdef SEGTREE_LAZY_ADD
const ll segtree_lazy_init = 0;
inline ll segtree_lazy_merge(ll a, ll b) {// 演算子aとbのマージ
	return a + b;
}
inline ll segtree_lazy_multi(ll a, ll n) {// 演算子aをn個つなげたもの
	return a * n;
}
inline ll segtree_lazy_divide(ll a) {// 演算子aを二個に分ける
	return a / 2;
}
inline ll segtree_lazy_apply(ll a, ll x) {// aに演算子xを適用する
	return a + x;
}
#endif
#ifdef SEGTREE_LAZY_MAX
const ll segtree_lazy_init = -INF;
inline ll segtree_lazy_merge(ll a, ll b) {// 演算子aとbのマージ
	return max(a, b);
}
inline ll segtree_lazy_multi(ll a, ll n) {// 演算子aをn個つなげたもの
	return a;
}
inline ll segtree_lazy_divide(ll a) {// 演算子aを二個に分ける
	return a;
}
inline ll segtree_lazy_apply(ll a, ll x) {// aに演算子xを適用する
	return max(a, x);
}
#endif
#ifdef SEGTREE_LAZY_MIN
const ll segtree_lazy_init = INF;
inline ll segtree_lazy_merge(ll a, ll b) {// 演算子aとbのマージ
	return min(a, b);
}
inline ll segtree_lazy_multi(ll a, ll n) {// 演算子aをn個つなげたもの
	return a;
}
inline ll segtree_lazy_divide(ll a) {// 演算子aを二個に分ける
	return a;
}
inline ll segtree_lazy_apply(ll a, ll x) {// aに演算子xを適用する
	return min(a, x);
}
#endif

template <class T> struct BIT : fenwick_tree<T> {
public:
	BIT() : fenwick_tree<T>() {}
	BIT(int n) : fenwick_tree<T>(n) {}
	BIT(const vector<T>& A) : fenwick_tree<T>((int)A.size()) {
		for (int i = 0; i < (int)A.size(); i++) {
			fenwick_tree<T>::add(i, A[i]);
		}
	}
	
	void get(int p) { return fenwick_tree<T>::sum(p, p + 1); }
	void set(int p, T x) { fenwick_tree<T>::add(p, x - get(p)); }
};

ll k;
bool func(ll x) {
	return x < k;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, Q; cin >> N >> Q;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	segtree<ll, segtree_data_merge, segtree_data_init> ST(A);

	for (int q = 0; q < Q; q++) {
		ll t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			ST.set(a - 1, b);
		}
		else if (t == 2) {
			cout << ST.prod(a - 1, b) << endl;
		}
		else {
			int ans = N;
			if (ST.prod(a - 1, N) >= b) {
				int L = a - 1, R = N;
				while (R - L > 1) {
					int c = (L + R) / 2;
					if (ST.prod(a - 1, c) >= b) { R = c; }
					else { L = c; }
				}
				ans = L;
			}
			//cout << ans + 1 << endl;
			k = b;
			cout << ST.max_right<func>(a - 1) + 1 << endl;
		}
	}

	return 0;
}