#if 1
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <set>
#include <map>
#include <numeric>
#include <cassert>
#include <iomanip>

using namespace std;
#define int long long
#define uint unsigned long long
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr int INF = 1145141919810893;

//
struct Edge {
	int next;
	int w = 1;
};
template<class T>
struct Vertex {
	std::vector<Edge>edges;
	T val = {};
};
template<class T>
struct Graph {
	std::vector<Vertex<T>> vertex;
public:
	Graph(size_t n = 0) :vertex(n) {
	}
	void setArray(int u, int v, int w = 1) {
		vertex[u].edges.push_back(Edge{ v ,w });
	}
	void setConnect(int u, int v, int w = 1) {
		setArray(u, v, w);
		setArray(v, u, w);
	}
	T& val(int u) {
		return vertex[u].val;
	}
	void dfsImpl(int pos, int prev, std::function<void(int now, int next, int w)> func) {
		for (auto& e : vertex[pos].edges) {
			if (e.next == prev) continue;
			func(pos, e.next, e.w);
			dfsImpl(e.next, pos, func);
		}
	}
	void dfs(int pos, std::function<void(int now, int next, int w)> func) {
		dfsImpl(pos, -1, func);
	}
	//graph.dfs(0, [](Vertex<int>& now, Vertex<int>& next, int w) {});
	pair<int, int> radiusImpl(int pos) {
		int farestID = -1;
		int far = -1;
		val(pos) = 0;
		dfs(pos, [&](int now, int next, int w) {
			val(next) = 1 + val(now);
			if (val(next) > far) {
				far = val(next);
				farestID = next;
			}
			});
		return { farestID, far };
	}
	int radius() {
		if (vertex.size() <= 1)return 0;
		auto res = radiusImpl(0);
		res = radiusImpl(res.first);
		return res.second;
	}
};

//////////////////////////////////
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

std::vector<int> divisor(int n) {
	std::vector<int> ret;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) {
				ret.push_back(n / i);
			}
		}
	}
	return ret;
}

////////////////////////

class Combination {
	std::vector<int>fac, finv, inv;
public:
	Combination(int N) :fac(N + 1), finv(N + 1), inv(N + 1) {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < N + 1; i++) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}
	int get(int n, int k) {
		if (n < k) return 0;
		if (n < 0 || k < 0) return 0;
		return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
	}
};


int modInv(int a) {
	int b = MOD, u = 1, v = 0;
	while (b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= MOD;
	if (u < 0) u += MOD;
	return u;
}


int modify(int& n) {
	if (n < 0) {
		n %= MOD;
		n += MOD;
	}
	n %= MOD;
}
//////////////////////


#define LOADVEC(type,name,N) std::vector<type>name(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name[nnn]; \
}

#define LOADVEC2(type,name0,name1,N) std::vector<type>name0(N),name1(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn]; \
}

#define LOADVEC3(type,name0,name1,name2,N) std::vector<type>name0(N),name1(N),name2(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn];cin >> name2[nnn]; \
}

#define LOAD(type,name) type name; \
cin >> name;


void proc();

signed main() {
	ios::sync_with_stdio(false);
	proc();
	return 0;
}

/*
--------------------------------------------------------
--------------------------------------------------------
---------------    template      ----------------------
--------------------------------------------------------
--------------------------------------------------------
*/


void proc() {
	LOAD(int, N);
	LOAD(int, M);
	LOAD(int, K);
	int inv3 = modInv(3);
	int inv2 = modInv(2);
	int res = ((N + M) * inv3) % MOD;
	res *= K;
	modify(res);
	res *= K - 1;
	modify(res);
	res *= inv2;
	modify(res);
	Combination co(N * M);
	res *= co.get(N * M, K);
	modify(res);
	cout << res << endl;
}


#endif
