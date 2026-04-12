//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <array>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<complex>
#include<assert.h>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

const double EPS = 1e-9;

/*template <typename T, typename E>
struct SegmentTree {
	typedef function<T(T, T)> F;//merge
	typedef function<T(T, E)> G;//dat lazy
	typedef function<E(E, E)> H;//lazy lazy
	typedef function<E(E, int)> P;//lazy len

	vector<T> dat; vector<E> laz;
	int n; F f; G g; H h;
	T d1;//datの単位元
	E d0;//lazyの単位元
	P p;

	SegmentTree(int m, F f, G g, H h, P p, T d1, E d0) : f(f), g(g), h(h), p(p), d1(d1), d0(d0)
	{
		n = 1;
		while (n < m) n *= 2;
		dat.assign(2 * n - 1, d1);
		laz.assign(2 * n - 1, d0);
	}
	
	void init(const vector<T> v)
	{
		for (int i = 0; i < SZ(v); i++) dat[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--) dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
	}

	inline void eval(int len, int k) 
	{
		if (laz[k] == d0) return;
		if (k * 2 + 1 < n * 2 - 1) 
		{
			laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
			laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
		}
		dat[k] = g(dat[k], p(laz[k], len));
		laz[k] = d0;
	}

	void update(int a, int b, E x, int k, int l, int r) 
	{
		eval(r - l, k);
		if (a <= l && r <= b) 
		{
			laz[k] = h(laz[k], x);
			eval(r - l, k);
		}
		else if (a < r&&l < b)
		{
			update(a, b, x, k * 2 + 1, l, (l + r) / 2);
			update(a, b, x, k * 2 + 2, (l + r) / 2, r);

			dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	T query(int a, int b, int k, int l, int r)
	{
		eval(r - l, k);
		if (r <= a || b <= l) return d1;
		if (a <= l && r <= b) return dat[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return f(vl, vr);
	}

	void update(int a, int b, E x) { update(a, b, x, 0, 0, n); }
	T query(int a, int b) { return query(a, b, 0, 0, n); }
	T operator[](const int &k) const { return dat[k + n - 1]; }
};*/

template <typename T>
struct SegmentTree {
	typedef function<T(T, T)> F;
	typedef function<bool(T)> C;

	int sz, n;
	vector<T> seg;
	const F f;
	const T M1;

	SegmentTree(int n, const F f, const T &M1) : f(f), M1(M1), n(n) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void init(const vector<T> v)
	{
		for (int i = 0; i < SZ(v); i++) seg[i + sz] = v[i];
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(int k, const T &x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	T query(int a, int b) {
		if (a >= b)return M1;
		T L = M1, R = M1;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	T operator[](const int &k) const {
		return seg[k + sz];
	}

	int find_subtree(int a, const C &check, T &M, bool type) {
		while (a < sz) {
			T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if (check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}

	//[a,x]が条件を満たす最初のx,満たさなければ-1
	int find_first(int a, const C &check) {
		T L = M1;
		if (a <= 0) {
			if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		int b = sz;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) {
				T nxt = f(L, seg[a]);
				if (check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	int find_last(int b, const C &check) {
		T R = M1;
		if (b >= sz) {
			if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		int a = sz;
		for (b += sz; a < b; a >>= 1, b >>= 1) {
			if (b & 1) {
				T nxt = f(seg[--b], R);
				if (check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}

	void print() {
		for (int i = 0; i < n; i++)if ((*this)[i] == M1)cout << "x "; else cout << (*this)[i] << " ";
		cout << endl;
	}
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;

	auto f = [&](int a, int b) {return max(a, b); };
	SegmentTree<int> st(N, f, 0);

	vector<int> P(N);
	rep(i, 0, N)cin >> P[i];
	st.init(P);

	int A, B, C;

	rep(i, 0, Q)
	{
		cin >> A >> B >> C;
		if (A == 1)st.update(B - 1, C);
		if (A == 2)cout << st.query(B - 1, C) << endl;
		if (A == 3)
		{
			auto p = [&](int a) {return a >= C; };
			int res = st.find_first(B - 1, p);
			if (res == -1)
			{
				cout << N + 1 << endl;
			}
			else
			{
				cout << res + 1 << endl;
			}
		}
	}

	return 0;
}
