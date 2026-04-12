#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4244) // 最悪をします
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <sstream>
#define BIT(nr) (1UL << (nr))
#define int long long
//#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }


using namespace std;

//デバッグ用カッコの有無
#ifdef DEBUG
template <class T>ostream& operator<<(ostream& o, const vector<T>& v)
{
	o << "{"; for (int i = 0; i < (int)v.size(); i++)o << (i > 0 ? ", " : "") << v[i]; o << "}"; return o;
}
#endif // DEBUG

template <class T>ostream& operator<<(ostream& o, const vector<T>& v)
{
	for (int i = 0; i < (int)v.size(); i++)o << (i > 0 ? " " : "") << v[i]; return o;
}

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

int dxp[4] = { 0, 1 }; // x軸方向への変位(正のみ)
int dyp[4] = { 1, 0 }; // y軸方向への変位(負のみ)

using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;

	// libalgo のものに追加、メンバを追加するだけなので互換性は崩さないはず、逆辺のG[e.dstの]インデックスを保持
	int rev;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0), cap(0), rev(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w), cap(0), rev(0) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph& g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph& g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

//出典 http://beet-aizu.hatenablog.com/entry/2017/12/01/225955
/*
コンストラクタ引数説明
int n_
要素数。
f
2つの要素Tをマージするための関数。
区間MAX区間更新の時: max
区間Sum区間Addの時: +
g
1つの要素Tに作用素Eを適用するための関数。
区間MAX区間更新の時: =
区間Sum区間Addの時: +
h
2つの作用素Eをマージするための関数。
区間MAX区間更新の時: =
区間Sum区間Addの時: +
T d1
演算fの単位元。
区間MAX区間更新の時: -INF　
区間Sum区間Addの時: 0
E d0,
g, hの単位元。
区間MAX区間更新の時: 定義域外のどこか
区間Sum区間Addの時: 0
vector<T> v = vector<T>()
セグ木を構成するときのvector
P p = [](E a, int b) {return a; }
区間の長さbを引数に取り、区間の長さによって変化する作用素E'を返す関数。
例えば、区間MAX区間Addの時なんかは区間長によって足すべき数が変化するので必要
区間Sum区間Addの時: *

//具体例
//区間chmin, 区間min
auto myMin = [](int a, int b) {return min(a, b); };
SegmentTree<int, int> seg(n, myMin, myMin, myMin, LL_HALFMAX, LL_HALFMAX);
//区間update、区間min
SegmentTree<int, int> seg(n, myMin, myMin, myMin, LL_HALFMAX, LL_HALFMAX);
//区間Add、区間Sum
vector<int> v(0, N + 1);
SegmentTree<int, int> segtree(N + 1, plus<int>(), plus<int>(), plus<int>(), 0, 0, v, [](int a, int b) {return a * b; });
//区間Add、区間Min
vector<int> v(0, N + 1);
SegmentTree<int, int> segtree(N + 1, myMin, plus<int>(), plus<int>(), LL_HALFMAX, 0, v, [](int a, int b) {return a; });
*/

template <typename T, typename E>
struct SegmentTree {
	typedef function<T(T, T)> F;
	typedef function<T(T, E)> G;
	typedef function<E(E, E)> H;
	typedef function<E(E, int)> P;
	int n;
	F f;
	G g;
	H h;
	P p;
	T d1;
	E d0;
	vector<T> dat;
	vector<E> laz;
	SegmentTree(int n_, F f, G g, H h, T d1, E d0,
		vector<T> v = vector<T>(), P p = [](E a, int b) {return a; }) :
		f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
		init(n_);
		if (n_ == (int)v.size()) build(n_, v);
	}
	//初期化。要素配列と遅延配列を2*n-1個にする
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat.clear();
		dat.resize(2 * n - 1, d1);
		laz.clear();
		laz.resize(2 * n - 1, d0);
	}
	//既存のvectorからセグ木を構築
	void build(int n_, vector<T> v) {
		for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--)
			dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
	}
	//ノードを評価する。
	inline void eval(int len, int k) {
		//遅延配列に単位元が入ってたら評価済みなのでおしまい
		if (laz[k] == d0) return;
		//葉ノードでないなら遅延伝播する
		if (k * 2 + 1 < n * 2 - 1) {
			//h: 2つの作用素を引数に取り合成した作用素を返す関数
			laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
			laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
		}
		//p: このノードに対応する区間長と作用素を引数に取り、区間長に対応する作用素を返す関数
		//dat[k] にlaz に溜めていた作用素を適用(g: 要素型と作用素型を引数に取り、要素に作用素を作用させた結果を返す関数、ここでの作用素とは区間Sum区間Addなら (+ 3) とか)
		dat[k] = g(dat[k], p(laz[k], len));
		//適用し終わったので遅延配列をクリア
		laz[k] = d0;
	}
	//[l,r)の区間を再帰的に見ながら0-indexedの[a, b)を更新する
	T update(int a, int b, E x, int k, int l, int r) {
		//先に評価
		eval(r - l, k);
		//範囲外ならなにもしないでそのノードが持つ値を返す
		if (r <= a || b <= l) return dat[k];
		//完全被覆なら既に遅延配列に入っている作用素と追加したい作用素をマージした後にそれを要素に作用させた結果を返す、pは区間長に対応する作用素を得るための（ｒｙ
		if (a <= l && r <= b) {
			laz[k] = h(laz[k], x);
			return g(dat[k], p(laz[k], r - l));
		}
		//完全被覆でも範囲外でもないなら(中途半端にかぶっているなら)完全被覆と範囲外の境界が見えるまで木を潜って変化後の値を得る
		return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
			update(a, b, x, k * 2 + 2, (l + r) / 2, r));
	}
	T update(int a, int b, E x) {
		return update(a, b, x, 0, 0, n);
	}

	T update(int a, E x) {
		return update(a, a + 1, x);
	}

	T query(int a, int b, int k, int l, int r) {
		eval(r - l, k);
		//範囲外なら単位元を返す
		if (r <= a || b <= l) return d1;
		//完全被覆ならそのまま返す
		if (a <= l && r <= b) return dat[k];
		//一部被覆なら完全被覆と範囲外に分かれるまで木を潜る
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return f(vl, vr);
	}
	//0-indexedで[a, b)の区間*を求める
	T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	T query(int a) {
		return query(a, a + 1, 0, 0, n);
	}

	void debug_print(int num) {
		vector<T> v;
		rep(i, num) {
			v.push_back(query(i));
		}
		cout << "{" << v << "}\n";
	}
};

// 座圧
class compress {
public:
	map<int, int> zip;
	vector<int> unzip;

	compress(vector<int> x) {
		sort(ALLOF(x));
		x.erase(unique(x.begin(), x.end()), x.end());
		rep(i, x.size()) {
			zip[x[i]] = i;
			unzip.push_back(x[i]);
		}
	}
};

signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	auto myMax = [&](int a, int b) -> int {
		return max(a, b);
	};
	auto myChg = [&](int a, int b) -> int {
		return b;
	};

	compress c(a);

	SegmentTree<int, int> dp(n + 10, myMax, myChg, myChg, -LL_HALFMAX, -LL_HALFMAX);
	dp.update(0, n + 1, 0);

	rep(i, n) {
		int ziped = c.zip[a[i]];

		int q = dp.query(ziped, n+2);

		int dp_ai = dp.query(ziped, ziped + 1);
		if (dp_ai < q + 1) {
			dp.update(ziped, q + 1);
		}
		//dp.debug_print(10);
	}

	int lis = dp.query(0, n + 1);
	cout << lis << "\n";

	return 0;
}
