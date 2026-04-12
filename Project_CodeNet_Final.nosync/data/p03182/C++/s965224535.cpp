//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 922337203685477580LL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

template<class T>
struct RMQ {
	T INF;
	int n;
	vector<T> dat, laz;
	RMQ(int n_) {
		INF = 0;
		n = 1;
		while(n < n_) n <<= 1;
		dat.assign(2*n-1, 0);
		laz.assign(2*n-1, 0);
	}
	inline int chld(int k) {return k*2+1;}
	inline int chrd(int k) {return k*2+2;}
	void eval(int k) {
		if(laz[k] == INF) return;
		if(k < n-1) {
			laz[chld(k)] += laz[k];
			laz[chrd(k)] += laz[k];
		}
		dat[k] += laz[k];
		laz[k] = INF;
	}
	void update(int a, int b, T x, int k, int l, int r) {
		eval(k);
		if(a <= l and r <= b) {
			laz[k] += x;
			eval(k);
		} else if(a < r and l < b) {
			update(a, b, x, chld(k), l, (l+r)>>1);
			update(a, b, x, chrd(k), (l+r)>>1, r);
			dat[k] = max(dat[chld(k)], dat[chrd(k)]);
		}
	}
	inline void update(int a, int b, T x) {update(a, b, x, 0, 0, n);}
	T query(int a, int b, int k, int l, int r) {
		eval(k);
		if(r <= a or b <= l) return INF;
		if(a <= l and r <= b) return dat[k];
		return max(query(a, b, chld(k), l, (l+r)>>1), query(a, b, chrd(k), (l+r)>>1, r));
	}
	inline T query(int a, int b) {return query(a, b, 0, 0, n);}
};

struct info {
	int l, r, a;
	bool operator<(const info &X) const {return r < X.r;}
};
const int N = 2e5+10;

//head

int n, m;
info lra[N];
RMQ<ll> rng(N);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	rep(i, m) {
		int l, r, a;
		cin >> l >> r >> a;
		l--; r--;
		lra[i] = (info){l, r, a};
	}
	sort(lra, lra+m);

	int j = 0;
	rep(i, n) {
		rng.update(i, i+1, rng.query(0, i));
		while(j != m and lra[j].r == i) {
			rng.update(lra[j].l, i+1, lra[j].a);
			j++;
		}
	}

	cout << rng.query(0, n) << endl;
}