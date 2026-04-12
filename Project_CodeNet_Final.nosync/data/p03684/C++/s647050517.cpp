#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <climits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <set>
#include <array>
#include <unordered_map>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define VS vector<string>
#define VI vector<ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define pcc pair<char,char>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define eps 1e-14
#define FST first
#define SEC second
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15)

namespace {
	struct input_returnner {
		ll N; input_returnner(ll N_ = 0) :N(N_) {}
		template<typename T> operator vector<T>() const { vector<T> res(N); for (auto &a : res) cin >> a; return std::move(res); }
		template<typename T> operator T() const { T res; cin >> res; return res; }
		template<typename T> T operator - (T right) { return T(input_returnner()) - right; }
		template<typename T> T operator + (T right) { return T(input_returnner()) + right; }
		template<typename T> T operator * (T right) { return T(input_returnner()) * right; }
		template<typename T> T operator / (T right) { return T(input_returnner()) / right; }
		template<typename T> T operator << (T right) { return T(input_returnner()) << right; }
		template<typename T> T operator >> (T right) { return T(input_returnner()) >> right; }
	};
	template<typename T> input_returnner in() { return in<T>(); }
	input_returnner in() { return input_returnner(); }
	input_returnner in(ll N) { return std::move(input_returnner(N)); }
}

const ll MOD = 1e9 + 7;

struct ModInt {
	ll v = 0;
	ModInt() {}
	template<class T> ModInt(const T& right) {
		v = right;
		if (v >= 0) v %= MOD;
		else v += ((-v) / MOD + 1)*MOD;
		v %= MOD;
	}
	void operator = (const ModInt& right) { v = right.v; }
	template<class T> void operator = (const T& right) {
		v = right;
		if (v >= 0) v %= MOD;
		else v = v += ((-v) / MOD + 1)*MOD;
		v %= MOD;
	}

	ModInt operator + (const ModInt& right) { return (v + right.v) % MOD; }
	ModInt operator - (const ModInt& right) { return (MOD - (v - right.v)); }
	ModInt operator * (const ModInt& right) { return (v * right.v) % MOD; }
	ModInt operator / (const ModInt& right) { return v / right.v; }

	void operator += (const ModInt& right) { v = (v + right.v) % MOD; }
	void operator -= (const ModInt& right) { v = (MOD - (v - right.v)); }
	void operator *= (const ModInt& right) { v = (v* right.v) % MOD; }
	void operator /= (const ModInt& right) { v = v / right.v; }

	bool operator == (const ModInt& right) { return v == right.v; }
};

ostream& operator << (ostream& os, const ModInt& value) {
	os << value.v;
	return os;
}

void solve();
/// ---template---

signed main(void) {
	SETUP;
	solve();
	return 0;
}

struct Edge {
	int f, t, c;
	Edge(int f_,int t_,int c_):f(f_),t(t_),c(c_){}
	Edge() {}
};


template <class T>
struct vector2 {
	T x;
	T y;
	vector2(T x_, T y_) :x(x_), y(y_) {}
	vector2() :x(0), y(0) {}
	vector2 operator + (const vector2<T>& right) { return vector2(x + right.x, y + right.y); }
	vector2 operator - (const vector2<T>& right) { return vector2(x - right.x, y - right.y); }
	T dot(const vector2<T>& right) { return x*right.x + y*right.y; }
	T det(const vector2<T>& right) { return (x*right.y) + (-y*right.x); }
};

#define int long long

class union_find {
private:
	vector<int> par;
	vector<int> rank;
	vector<int> count;
public:
	union_find(int N) :par(N), rank(N, 0), count(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}

	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;

		if (rank[x] < rank[y]) {
			count[y] += count[x];
			par[x] = y;
		}
		else {
			count[x] += count[y];
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	int getCount(int x) {
		return count[find(x)];
	}

	void clean() {
		par = vector<int>(par.size());
	}
};


void solve() {
	int N; cin >> N;
	vector<pair<pii, int>> P(N);
	REP(i, N) {
		cin >> P[i].first.first >> P[i].first.second;
		P[i].second = i;
	}
	using mytype = pair<int, pair<int, int>>;
	priority_queue<mytype, vector<mytype>, greater<mytype>> q;
	sort(ALL(P));
	REP(i, N-1) {
		q.push(MP( P[i + 1].first.first - P[i].first.first, MP( P[i].second, P[i+1].second ) ));
	}
	sort(ALL(P), 
		[](const pair<pii,int>&left, const pair<pii,int>& right) -> bool{
		if (left.first.second != right.first.second) {
			return left.first.second < right.first.second;
		}
		else left < right;
	}
	);
	REP(i, N-1) {
		q.push(MP( P[i + 1].first.second - P[i].first.second, MP( P[i].second, P[i+1].second ) ));
	}

	union_find uf(N+1);

	int res = 0;
	while(not q.empty()){
		auto a = q.top();
		q.pop();
		if (not uf.same(a.second.first, a.second.second)) {
			uf.unite(a.second.first, a.second.second);
			res += a.first;
		}
	}
	cout << res << endl;
}
