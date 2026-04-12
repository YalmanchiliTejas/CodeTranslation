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

// v:vector  type:型  order:greater(大きい順) or less(小さい順)
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
/*
	◆pairでもソートは可能

	vector<pair<int32_t, bool>> pr(n);
	sort(pr.begin(), pr.end(),_compare);

	bool _compare(pair<int32_t, bool> a, pair<int32_t, bool> b) {

		// firstで比較する場合
		if (a.first != b.first) {
			return a.first < b.first;	// 昇順
			return a.first > b.first;	// 降順
		}
		// どちらも同じ
		return true;

		// secondで比較する場合
		if (a.second != b.second) {
			return a.second < b.second;	// 昇順
			return a.second > b.second;	// 降順
		}
		// どちらも同じ
		return true;
	}

*/

// vector 要素の総和算出
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
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
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

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

// 順列 n個の数が与えられる
// 0,1,2,...,n-1
// 全ての並べ方を1行ごとに出力する
// ex 0 1 2 / 0 2 1 / 1 0 2 / 1 2 0 / 2 0 1 / 2 1 0
#define _next_permutation(v) do {     \
	for (auto num : v) {              \
		printf("%d ", num);           \
	}                                 \
	printf("\n");                     \
	/* ※ 昇順である必要がある     */ \
	/* ※ pair も pair.firstで可能 */ \
} while (next_permutation(v.begin(), v.end()))

// 絶対値
template<typename T>
static T _abs(const T x) { return  (x > 0 ? x : -x); }

// 最大公約数
int64_t gcd(int64_t a, int64_t b) { while (b) { int64_t c = b; b = a % b; a = c; } return a; }
// 最小公倍数
int64_t lcm(int64_t a, int64_t b) { if (!a || !b) return 0; return a * b / gcd(a, b); }

// 多次元 std::vector 生成
template<class T>
vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...)); }
// ex) auto dp = make_vec<uint64_t>(SIZE + 1, 2, 2);

// pair
// vector<vector<pair<int32_t,int32_t>>> f(n);
// ⇒ 挿入 f[i].push_back(make_pair(x, y));

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

/*************************************************************/
// ABC 107
// B -  Grid Compression
// https://atcoder.jp/contests/abc107/tasks/abc107_b
/*
	■問題文
	縦 H 行、横 W 列のマス目があります。 
	上から i 行目、左から j 列目のマスを (i,j) と表します。 
	各マスは白または黒です。 
	マス目の配色は、H 行 W 列の行列 (ai,j) によって与えられます。 
	ai,j が . ならばマス (i,j) は白であり、ai,j が # ならばマス (i,j) は黒です。
	すぬけ君はこのマス目を圧縮しようとしています。 
	そのために、白いマスのみからなる行または列が存在する間、次の操作を繰り返し行います。

    操作: 白いマスのみからなる行または列をひとつ任意に選び、その行または列を取り除いて空白を詰める。
	各操作でどの行または列を選ぶかによらず、最終的なマス目は一意に定まることが示せます。 最終的なマス目を求めてください。

	■制約
	・1 ≤ H,W ≤ 100
	・ai,j は . または # である。
	・マス目全体で少なくともひとつは黒いマスが存在する。

	■入力
	H W
	a1,1...a1,W
	:
	aH,1...aH,W
	
	■出力
	最終的なマス目を、入力と同様のフォーマットで出力せよ。 
	ただし、行数および列数は省くこと。 詳しくはサンプルを参照せよ。

	■入力例
	4 4
	##.#
	....
	##.#
	.#.#

	■出力例
	###
	###
	.##

	元のマス目における第 2 行および第 3 列がそれぞれ取り除かれます。
*/

static char v[100][100];
int main()
{
	int32_t h, w;
	cin >> h >> w;

	bool is_continues;
	for (int32_t i = 0; i < h; i++) {
		is_continues = true;
		for (int32_t j = 0; j < w; j++) {
			cin >> v[i][j];
			if (v[i][j] == '.') { continue; }
			is_continues = false;
		}

		if (!is_continues) { continue; }
		for (int32_t j = 0; j < w; j++) {
			v[i][j] = 0;
		}
	}

	for (int32_t j = 0; j < w; j++) {
		is_continues = true;
		for (int32_t i = 0; i < h; i++) {
			if (v[i][j] == '.' || v[i][j] == 0) { continue; }
			is_continues = false;
			break;
		}
		if (!is_continues) { continue; }
		for (int32_t i = 0; i < h; i++) {
			v[i][j] = 0;
		}
	}

	for (int32_t i = 0; i < h; i++) {
		is_continues = false;
		for (int32_t j = 0; j < w; j++) {
			if (!v[i][j]) { continue; }
			is_continues = true;
			if (v[i][j] == 35) {
				printf("#"); 
				continue;
			}
			printf("."); 
		}
		if (!is_continues) { continue; }
		printf("\n");
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
