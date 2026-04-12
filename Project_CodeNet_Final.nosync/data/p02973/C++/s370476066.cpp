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
#define _SCL_SECURE_NO_WARNINGS
#include "boost/multiprecision/cpp_int.hpp"

#pragma warning (disable:4244)


using namespace std;

using int128 = boost::multiprecision::int128_t;
#if 0
#define int boost::multiprecision::int128_t
#else
#define int long long
#endif
constexpr long long MOD = 1000000007LL;
//constexpr int MOD = 998244353;
constexpr long long INF = 1145141919810893LL;

//
#if 1



//ダイクストラ法を使うときはTとしてこれを継承したものを使う
struct Dijk {
	int dijk;
};
struct Edge {
	int next;
	int w = 1;
};
template<class T>
struct Vertex {
	std::vector<Edge>edges;
	T val;
};
template<class T>
struct Graph {
	std::vector<Vertex<T>> vertex;
public:
	Graph(size_t nVertex = 0) :vertex(nVertex) {
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
	void dfsImpl(int pos, int prev, std::function<bool(int now, int next, int w)> func) {
		for (auto& e : vertex[pos].edges) {
			if (e.next == prev) continue;
			if (func(pos, e.next, e.w)) {
				dfsImpl(e.next, pos, func);
			}
			//ここに追加する場合も
		}
	}
	void dfsCustom(int pos, int prev);
	//深さ優先探索
	void dfs(int pos, std::function<bool(int now, int next, int w)> func) {
		dfsImpl(pos, -1, func);
	}
	//幅優先探索
	void bfs(int pos, std::function<bool(int now, int next, int w)> func) {
		std::unordered_set<int> set;
		set.insert(pos);
		while (!set.empty()) {
			std::unordered_set<int> setNew;
			for (auto& one : set) {
				for (auto& e : vertex[one].edges) {
					if (func(one, e.next, e.w)) {
						setNew.insert(e.next);
					}
				}
			}
			set = setNew;
		}
	}
	//
	void dijkstra(int pos) {
		for (int i = 0; i < vertex.size(); ++i) {
			val(i).dijk = -1;
		}
		val(pos).dijk = 0;
		//
		bfs(pos, [&](int now, int next, int w) {
			if (val(next).dijk<0 || val(next).dijk>val(now).dijk + w) {
				val(next).dijk = val(now).dijk + w;
				return true;
			}
			return false;
			});
	}
	pair<int, int> radiusImpl(int pos) {
		int farestID = -1;
		int far = -1;
		val(pos) = 0;
		//dfsで正しい？？
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
#endif

//////////////////////////////////
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }

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

bool isPrime(int n) {
	if (n <= 1)return false;
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)return false;
	}
	return true;
}

////////////////////////
#if 1
//二項係数、int128は使わなく64で十分
class Combination {
	std::vector<long long>fac, finv, inv;
public:
	Combination(long long N) :fac(N + 1), finv(N + 1), inv(N + 1) {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (long long i = 2; i < N + 1; i++) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}
	long long get(long long n, long long k) {
		if (n < k) return 0;
		if (n < 0 || k < 0) return 0;
		return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
	}
};

#endif
#if 1

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

template <class T>
void modify(T& n, T mod = MOD) {
	if (n < 0) {
		n %= mod;
		n += mod;
	}
	n %= mod;
}

#endif

//文字列の置き換え(遅い？)
int replace(std::string* str, const std::string& old_, const std::string& new_) {
	std::string& String1 = *str;
	//String1.reserve(str->size() * new_.size() / old_.size() + 1);
	std::string::size_type  Pos(String1.find(old_));
	int result = 0;
	while (Pos != std::string::npos) {
		result++;
		String1.replace(Pos, old_.length(), new_);
		Pos = String1.find(old_, Pos + new_.length());
	}
	return result;
}

//座標圧縮(未完成)
struct Compressor {
	std::unordered_map<int, int> m;
};

//MODで割ったあまりの演算
struct Rational {
	int r;
	Rational(int rr) :r(rr) {
	}
	operator int() {
		return r;
	}
	Rational operator+(const Rational& other)const {
		Rational res(0);
		res.r = r + other.r;
		modify(res.r);
		return res;
	}
	Rational operator-(const Rational& other)const {
		Rational res(0);
		res.r = r - other.r;
		modify(res.r);
		return res;
	}
	Rational operator*(const Rational& other) const {
		Rational res(0);
		res.r = r * other.r;
		modify(res.r);
		return res;
	}
	Rational operator/(const Rational& other)const {
		Rational res(0), res1(0);
		res = *this;
		res1.r = modInv(other.r);
		res = (*this) * res1;
		modify(res.r);
		return res;
	}
	void operator+=(const Rational& other) {
		*this = *this + other;
	}
	void operator-=(const Rational& other) {
		*this = *this - other;
	}
	void operator*=(const Rational& other) {
		*this = *this * other;
	}
	void operator/=(const Rational& other) {
		*this = *this / other;
	}
};

Rational pow(Rational r, int N) {
	if (N == 0)return Rational(1);
	if (N % 2 == 1)return r * pow(r, N - 1);
	Rational tmp = pow(r, N / 2);
	return tmp * tmp;
}
Rational operator"" _r(unsigned long long val) {
	return Rational(val);
}

/////////////////////

template <class T>
void SORT(T& t) {
	std::sort(t.begin(), t.end());
}

template <class T, class U>
void FILL(T& t, const U& val) {
	std::fill(t.begin(), t.end(), val);
}

template <class T>
void MAX(T& val, T min) {
	val = std::max({ val,min });
}

template <class T>
void MIN(T& val, T min) {
	val = std::min({ val,min });
}

template <class T>
void PRINT(const T& con) {
	cout << "(";
	for (auto& one : con) {
		cout << one << ",";
	}
	cout << ")" << endl;
}


constexpr double pi = 3.141592653589793238462;
//////////////////

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
	cout << std::setprecision(20);
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



#if 0

struct S {
	int dis = -1;
};

template<class T>
void Graph<T>::dfsCustom(int pos, int prev) {
	int nEdge = 0;
	for (auto& e : vertex[pos].edges) {
		const int next = e.next;
		if (next == prev) continue;
		if (val(next).dis == -1) {
			val(next).dis = val(pos).dis + 1;
			dfsCustom(next, pos);
			++nEdge;
		}
		else if (val(next).dis < val(pos).dis) {
			//ここに来たなら木ではない(後退辺の処理)
			assert(false);
		}
	}
	//
	int rat = K - 1;
	if (val(pos).dis == 0) {
		for (int i = 0; i < nEdge; ++i) {
			res *= rat;
			modify(res);
			--rat;
		}
	}
	else {
		--rat;
		for (int i = 0; i < nEdge; ++i) {
			res *= rat;
			modify(res);
			--rat;
		}
	}
}

#endif

void proc() {
	LOAD(int, N);
	LOADVEC(int, A, N);
	std::map<int, int> dp;
	for (int i = 0; i < N; ++i) {
		auto itr = dp.lower_bound(-A[i] + 1);
		if (itr == dp.end()) {
			dp[-A[i]]++;
		}
		else {
			dp[itr->first]--;
			if (dp[itr->first] == 0) {
				dp.erase(itr);
			}
			else {
			}
			dp[-A[i]]++;
		}
	}
	int res = 0;
	for (auto one : dp) {
		res += one.second;
	}
	cout << res << endl;


	//
}


#endif


