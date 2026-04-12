// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <bitset>
using namespace std;

#define ll long long
#define ld long double
#define pi 3.14159265359;
// %llu %lf

// double result = 0;
// printf("%.12f\n", result);

// 昇順
#define _vsort(v) do { sort(v.begin(),v.end()); } while(0)
// 降順
#define _vsortr(v) do { sort(v.rbegin(),v.rend()); } while(0)
/*
	◆map のソート
	key   はソート済
	value でソートする場合は一度他vectorへ格納してソートする


	◆pairでもソートは可能
	vector<pair<int32_t, int32_t>> pr(n);
	sort(pr.begin(), pr.end(),_compare);

	bool _compare(pair<int32_t, int32_t> a, pair<int32_t, int32_t> b)
	{

	#if 0	// first での sort

	#if 0
		// 昇順
		if (a.first != b.first) {
			return a.first < b.first;
		}
		// secondが同じならfirstでソート
		return a.second < b.second;
	#else
		// 降順
		if (a.first != b.first) {
			return a.first > b.first;
		}
		// secondが同じならfirstでソート
		return a.second > b.second;
	#endif

	#else	// second での sort

	#if 1
		// 昇順
		if (a.second != b.second) {
			return a.second < b.second;
		}
		// secondが同じならfirstでソート
		return a.first < b.first;
	#else
		// 降順
		if (a.second != b.second) {
			return a.second > b.second;
		}
		// secondが同じならfirstでソート
		return a.first > b.first;
	#endif

	#endif

	}

*/

// vector 要素の総和算出
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
/*
	int32_t n = 21;
	----------------------------
	int32_t sum = 0;
	for (int32_t i = 1; i <= n; i++) {
		sum += i;
	}
	----------------------------
		↑と同じ結果が得られる
	----------------------------
	sum = n * (n + 1) / 2;
	----------------------------
*/

// vector 最大値( return ite )
#define _max_element(v) max_element(v.begin(),v.end())
// vector 最小値( return ite )
#define _min_element(v) min_element(v.begin(),v.end())
// vector 最大値が格納されている要素値
#define _max_element_number(v) distance(v.begin(),max_element(v.begin(),v.end()))
// 特定コンテナの中から特定の値をカウントする
#define _count(v,value) count(v.begin(),v.end(),value)

//set<uint32_t> member;	// 重複するデータを保持する事はできない member.insert(2) member.insert(2) ⇒ member.count(2)は1
//                                                              member.emplace(2)とかも同じ member.size()で確認すると同じ値の挿入ではサイズ変化はない
//multiset<uint32_t> v;	// 重複するデータも保持する事はできる   member.insert(2) member.insert(2) ⇒ member.count(2)は2

// 丸め
// double temp = 9.5;
// int32_t a = (int32_t)_round(temp);
// ⇒ 10
// double temp = 9.4;
// int32_t a = (int32_t)_round(temp);
// ⇒ 9
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)
template <class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

// string ⇒ int
#define _stringtoi(s) stoi(s)
// double 平方根
#define _sqrt(x) sqrt(x)
// double 引数 x 以上で最小の整数値 ex) 3.30303 ⇒ 4
#define _ceil(x) ceil(x)
// 指定された要素 【以上の】　　値が現れる最初の位置のイテレータを取得する
#define _lower_bound(v,min) lower_bound(v.begin(), v.end(), min)
// 指定された要素 【より大きい】値が現れる最初の位置のイテレータを取得する
#define _upper_bound(v,min) upper_bound(v.begin(), v.end(), min)

// ■順列 n個の数が与えられる
// 0,1,2,...,n-1
// 全ての並べ方を1行ごとに出力する
// ex 0 1 2 / 0 2 1 / 1 0 2 / 1 2 0 / 2 0 1 / 2 1 0
/*
	do {
		for (auto num : v) {
			printf("%d ", num);
		}
		printf("\n");
	} while (next_permutation(v.begin(), v.end()))
	// ※ 昇順である必要がある
	// ※ pair も pair.firstで可能
*/

// ■組み合わせ問題
/* powでいいけど、MODで除算する系の問題
#define MOD 1000000007 //10^9+7:合同式の法
int64_t powmod(int64_t x, int64_t n)
{
	int64_t ret = 1;

	while (n > 0) {
		// n の最下位bitが1ならば(nが奇数ならば) x^(2^i) をかける
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		// n を1bit 左にずらす
		n >>= 1;
	}

	return ret;
}

// n個の中から、r個を選ぶ組み合わせ
// n個の中から、任意の個数を選ぶ組み合わせ ⇒ 2^n
int64_t nCr(const int64_t n, const int64_t r)
{
	int64_t x = 1, y = 1;

	for (int64_t i = 0; i < r; i++) {
		x = x * (n - i) % MOD;
		y = y * (i + 1) % MOD;
	}

	return (x * powmod(y, MOD - 2) % MOD);
}
*/

// ■bitset
// 100 桁の 2 進数を定義する。
// bitset<100> bs;
// 
// 8桁 の 2進数を定義し、10進数 131で初期化
// bitset<8> bs(131);			// 7 ビット目から 0 ビット目への順番で、10000011 になる
// 
// 8桁 の 2進数を定義し、2進数で初期化
// bitset<8> bs("10000011");	// 7 ビット目から 0 ビット目への順番で、10000011 となる。
// string _bs; cin >> _bs; bitset<100> bs(_bs); _bs = "10000011"であれば上記と同様
// 
// 与えられる数値について、それぞれの和を算出する場合
// 下記コードでビットが立っている要素値＝和の値となる
// ex.) AGC 020 C https://atcoder.jp/contests/agc020/tasks/agc020_c
// bitset<1000> dp;
// p[0] = 1;
// for (int i = 0; i < N; ++i) {
//    dp |= (dp << A[i]);
// }

// 絶対値
template<typename T>
static T _abs(const T x) { return  (x > 0 ? x : -x); }

// 最大公約数
int64_t gcd(int64_t a, int64_t b) { while (b) { int64_t c = b; b = a % b; a = c; } return a; }
// 最小公倍数
int64_t lcm(int64_t a, int64_t b) { if (!a || !b) return 0; return (a / gcd(a, b) * b); }

// 多次元 std::vector 生成
template<class T>
vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...)); }
// ex) auto dp = make_vec<uint64_t>(SIZE + 1, 2, 2);
//
// 2次元 vector の初期化
// vector< vector<int> >  s( n, vector<int>(m, 0) );

// pair
// vector<vector<pair<int32_t,int32_t>>> f(n);
// ⇒ 挿入 f[i].push_back(make_pair(x, y));

//////////////////////////////////////////////////
// ABC 146 C Buy an Integer
// 10進桁数算出
int32_t digit(int64_t a)
{
	int32_t digit_count = 0;
	while (a > 0) { a /= 10; digit_count++; }
	return digit_count;
}

// 2分探索
int64_t a, b;
int64_t x;

int64_t find_binary_search(bool is_upper, int64_t left, int64_t right)
{
	int64_t mid;
	while (right - left > 1) {
		mid = (left + right) / 2;
		if ((a*mid) + (b*digit(mid)) > x) { right = mid; }
		else { left = mid; }
	}

	if (is_upper) { return right; }
	return left;
}
//////////////////////////////////////////////////

// Union Find Tree
class UnionFind
{
public:
	vector <int32_t> par; // 各元の親を表す配列
	vector <int32_t> siz; // 素集合のサイズを表す配列(1 で初期化)

	// Constructor 初期では親は自分自身
	UnionFind(int32_t sz_) : par(sz_), siz(sz_, 1LL) { for (int32_t i = 0; i < sz_; ++i) par[i] = i; }

	void init(int32_t sz_)
	{
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (int32_t i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Find
	int32_t root(int32_t x)
	{
		// x の親の親を x の親とする
		while (par[x] != x) {
			x = par[x] = par[par[x]];
			//			printf("%d\n", x);
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(int32_t x, int32_t y)
	{
		x = root(x);
		y = root(y);
		if (x == y) return false;
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	// 連結判定
	bool is_same(int32_t x, int32_t y) { return root(x) == root(y); }

	// 素集合のサイズ
	int32_t size(int32_t x) { return siz[root(x)]; }

	// 参照
	void view(void) {
		for (size_t i = 0; i < par.size(); i++) {
			printf("%d\n", par[i]);
		}
	}

};

// ■
// UINT32_MAX
// 4294967295 ≒ 4 * 1e9

// ■
// 割り算した結果との比較での丸め対処時 
// ABC 161 B
// https://atcoder.jp/contests/abc161/tasks/abc161_b
// double   border = _sum(v, 0 / (double)(4 * m);
//            ↓
// uint32_t border = (_sum(v, 0) + (4 * m) - 1) / (4 * m);

// ■
// 1+2+3+4+5+6+7+・・・+n のような 1 から連続する値のは和
// (n*(n + 1)) / 2 にて求められる

// ■
// l～r 間でdで割り切れる数の個数
// r/d - (l-1)/d;

// ■
// 和がKの倍数である数の組が存在する時、それぞれの数の mod Kの和はKの倍数
// という考え方がよく出てくるみたい。数式で表すと、
//
// ( a + b + ... ) % K = 0 のとき、a % K + b % K +... = nK (n=1,2,...)

// ■ 等比数列の和
// a( 1 - rのn乗 ) / 1 - r
// 例えば
// a = 7 として 77777777・・・の数列を作るとした場合 7(1+10+100+1000・・・) = 7( 10のn乗 - 1 ) / ( 10 - 1 )
// で表現できる
// ⇒ 割り算のひっ算でよい 77777777・・・と巨大な整数を割っていく場合
/*
	uint64_t でも収まらないような巨大な整数 77777777・・・に対する割り算を可能にする為、
	下記のように 1 桁毎処理していく
	uint32_t dividend_value = 0;
	for (uint32_t i = 1; i < k; i++) {

		/// 割り算のひっ算と同処理 ////
		dividend_value *= 10;
		// ↓テーブル用意⇒ループで与えていく事であらゆる巨大な数でも演算可能
		dividend_value += 7;
		dividend_value %= k;
		///////////////////////////////
 
		if (dividend_value) { continue; }
		cout << i << endl;
		return 0;
	}
*/

/*************************************************************/
// ABC x
// x - x
// -
/*
	■問題文

	■制約

	■入力

	■出力

	■入力例
	
	■出力例
*/

int main(void)
{
	int32_t h, w;
	cin >> h >> w;

	vector<string> v(h);
	for (int32_t i = 0; i < h; i++) {
		cin >> v[i];

		int32_t j;
		for (j = 0; j < w; j++) {
			if (v[i][j] == '.') { continue; }
			break;
		}

		if (j < w) { continue; }
		for (j = 0; j < w; j++) {
			v[i][j] = 0;
		}
	}

	for (int32_t i = 0; i < w; i++) {
		int32_t j;
		for (j = 0; j < h; j++) {
			if (v[j][i] == '.' || v[j][i] == 0) { continue; }
			break;
		}

		if (j < h) { continue; }
		for (j = 0; j < h; j++) {
			v[j][i] = 0;
		}
	}

	for (int32_t i = 0; i < h; i++) {

		string str;
		for (int32_t j = 0; j < w; j++) {
			if (v[i][j] == 0) { continue; }
			str += v[i][j];
		}

		if (str.empty()) { continue; }
		cout << str << endl;
	}

	return 0;
}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
