#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>
#include<functional>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;
const long long ll_max = 9223372036854775807;
const long long ll_min = -9223372036854775807;
const int int_max = 2147483647;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> getPrimeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

template<typename T>
bool IsPrimeNumber(T num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
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

// セグメント木　学習中
template <class T>
class SegmentTree {
	int n;	// 葉の数
	vector<T> data;	// データを格納するvector
	T def;	// 初期値かつ単位元
	function<T(T, T)> operation; // 区間クエリで使う処理
	function<T(T, T)> update;	// 点更新で使う処理

	// 区間[a,b)の総和。ノードk=[l,r)に着目している。
	T _query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return def; // 交差しない
		if (a <= l && r <= b)
			return data[k]; // a,l,r,bの順で完全に含まれる
		else {
			return operation(_query(a, b, 2 * k + 1, l, (l + r) / 2), _query(a, b, 2 * k + 2, (l + r) / 2, r));	//左右を分割して再帰
		}
	}

public:
	// _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
	// _update:更新関数
	SegmentTree(size_t _n, T _def, function<T(T, T)> _operation,
		function<T(T, T)> _update)
		: def(_def), operation(_operation), update(_update) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		data = vector<T>(2 * n - 1, def);
	}

	// 場所i(0-indexed)の値をxで更新
	void change(int i, T x) {
		i += n - 1;
		data[i] = update(data[i], x);
		while (i > 0) {
			i = (i - 1) / 2;
			data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
		}
	}

	// [a, b)の区間クエリを実行
	T query(int a, int b) {
		return _query(a, b, 0, 0, n);
	}

	// 添字でアクセス
	T operator[](int i) {
		return data[i + n - 1];
	}
};

// 繰り返し二乗法
ll pow2(ll n, ll p, ll mod) {
	if (p == 0 || n == 1) {
		return 1;
	}
	else {
		ll ret = pow2(n * n % mod, p / 2, mod);
		if (p % 2 == 1) {
			ret *= n;
		}
		return ret % mod;
	}
}


#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)


int main() {
	ll H, W;
	cin >> H >> W;
	vector<string> A(H);
	rep(i, 0, H) {
		cin >> A[i];
	}

	bool ans = true;

	vector<pair<ll, ll>> mov = { {0,1},{1,0},{0,-1},{-1,0} };
	ll x, y;
	stack<pair<ll, ll>> st({ {0,0} });
	while (ans && !st.empty()) {
		x = st.top().first;
		y = st.top().second;
		st.pop();
		A[x][y] = '.';

		rep(i, 0, 2) {
			ll xx = x + mov[i].first;
			ll yy = y + mov[i].second;
			if (xx < H && yy < W && A[xx][yy] == '#') {
				st.push({ xx,yy });
			}
		}

		if (st.size() > 1) {
			ans = false;
			break;
		}


		rep(i, 2, 4) {
			ll xx = x + mov[i].first;
			ll yy = y + mov[i].second;
			if (0 <= xx && 0 <= yy && A[xx][yy] == '#') {
				ans = false;
				break;
			}
		}
	}


	if (ans && x == H - 1 && y == W - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

	return 0;
}
