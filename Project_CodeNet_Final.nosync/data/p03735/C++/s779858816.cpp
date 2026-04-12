
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
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
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)

ll x[202020], y[202020];
int N;

struct minSegmenttree {
	static const int N = 1 << 18;
	vector<ll>seg;
	vector<ll>idx;
	void st(ll p, ll v) {
		p += N - 1;
		seg[p] = v;
		idx[p] = p - N + 1;
		while (p > 0) {
			p = (p - 1) / 2;
			seg[p] = min(seg[2 * p + 1], seg[2 * p + 2]);
			if (seg[2 * p + 1] > seg[2 * p + 2])idx[p] = idx[2 * p + 2];
			else if (seg[2 * p + 1] < seg[2 * p + 2])idx[p] = idx[2 * p + 1];
			else idx[p] = min(idx[2 * p + 1], idx[2 * p + 2]);
		}
	}
	pair<ll, ll> query(ll l, ll r, ll a, ll b, ll k) {
		if (r <= a || b <= l)return { inf,inf };
		if (l <= a && b <= r)return { seg[k],idx[k] };
		ll m = (a + b) / 2;
		auto p1 = query(l, r, a, m, 2 * k + 1);
		auto p2 = query(l, r, m, b, 2 * k + 2);
		if (p1.first < p2.first) return p1;
		else if (p1.first > p2.first)return p2;
		else return { p1.first,min(p1.second,p2.second) };
	}

	void init() {
		seg.resize(2 * N);
		idx.resize(2 * N);
		for (int i = 0; i < 2 * N; i++)seg[i] = inf;
	}
	//[l,r)
	ll get(int l, int r) {
		return query(l, r, 0, N, 0).first;
	}
	ll getidx(int l, int r) {
		return query(l, r, 0, N, 0).second;
	}
	pair<ll, ll>getp(int l, int r) {
		return query(l, r, 0, N, 0);
	}
};

struct maxSegmenttree {
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
	//[l,r)
	ll get(int l, int r) {
		return query(l, r, 0, N, 0).first;
	}
	ll getidx(int l, int r) {
		return query(l, r, 0, N, 0).second;
	}
	pair<ll, ll>getp(int l, int r) {
		return query(l, r, 0, N, 0);
	}
};

ll solve(){
	vector<pair<ll,ll>>xy(N);
	for (int i = 0; i < N; i++)xy[i] = {min(x[i],y[i]),max(x[i],y[i])};
	sort(all(xy));
	minSegmenttree xmseg = minSegmenttree();
	maxSegmenttree xMseg = maxSegmenttree();
	minSegmenttree ymseg = minSegmenttree();
	maxSegmenttree yMseg = maxSegmenttree();

	xmseg.init();
	xMseg.init();
	ymseg.init();
	yMseg.init();
	for (int i = 0; i < N; i++) {
		xmseg.st(i,xy[i].first);
		xMseg.st(i,xy[i].first);
		ymseg.st(i,xy[i].second);
		yMseg.st(i,xy[i].second);
	}

	ll ans = inf;

	for (int i = 0; i < N; i++) {
		ll Rmax = max(xMseg.get(0,i),yMseg.get(i,N));
		ll Rmin = min(xmseg.get(0,i),ymseg.get(i,N));
		ll Bmax = max(yMseg.get(0,i),xMseg.get(i,N));
		ll Bmin = min(ymseg.get(0,i),xmseg.get(i,N));
		ans = min((Rmax-Rmin)*(Bmax-Bmin),ans);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)cin >> x[i] >> y[i];
	puts(solve());
	
	return 0;
}
