
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<complex>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#include <numeric>
using namespace std;
using Complex = complex<double>;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1145141919810364364LL;
const double EPS = 1e-10;
double PI = acos(-1.0);
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)

struct Segmenttree {
	static const int N = 1 << 18;
	vector<ll>seg;
	vector<ll>idx;
	void st(ll p, ll v) {
		p += N - 1;
		seg[p] = v;
		idx[p] = p - N + 1;
		while (p > 0) {
			p = (p - 1) / 2;
			seg[p] = max(seg[2 * p + 1], seg[2 * p + 2]);
			if (seg[2 * p + 1] < seg[2 * p + 2])idx[p] = idx[2 * p + 2];
			else if (seg[2 * p + 1] > seg[2 * p + 2])idx[p] = idx[2 * p + 1];
			else idx[p] = min(idx[2 * p + 1], idx[2 * p + 2]);
		}
	}
	pair<ll, ll> query(ll l, ll r, ll a, ll b, ll k) {
		if (r <= a || b <= l)return { -inf,inf };
		if (l <= a && b <= r)return { seg[k],idx[k] };
		ll m = (a + b) / 2;
		auto p1 = query(l, r, a, m, 2 * k + 1);
		auto p2 = query(l, r, m, b, 2 * k + 2);
		if (p1.first > p2.first) return p1;
		else if (p1.first < p2.first)return p2;
		else return { p1.first,min(p1.second,p2.second) };
	}

	void init() {
		seg.resize(2 * N);
		idx.resize(2 * N);
		for (int i = 0; i < 2 * N; i++)seg[i] = -inf;
	}
	//[l,r]
	ll get(int l, int r) {
		return query(l, r + 1, 0, N, 0).first;
	}
	ll getidx(int l, int r) {
		return query(l, r + 1, 0, N, 0).second;
	}
	pair<ll, ll>getp(int l, int r) {
		return query(l, r + 1, 0, N, 0);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	Segmenttree seg = Segmenttree();
	seg.init();
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		seg.st(i,a);
	}

	for (int i = 0; i < Q; i++) {
		int T;
		cin >> T;
		if (T == 1) {
			int X, V;
			cin >> X >> V;
			X--;
			seg.st(X,V);
		}
		else if (T == 2) {
			int L, R;
			cin >> L >> R;
			L--;
			R--;
			puts(seg.get(L, R));
		}
		else {
			int X, V;
			cin >> X >> V;
			X--;
			int ng = X-1, ok = N;
			while (ok - ng > 1) {
				int mid = (ok + ng) / 2;
				if (seg.get(X,mid) >= V)ok = mid;
				else ng = mid;
			}
			puts(ok + 1);
		}
	}
	return 0;
}