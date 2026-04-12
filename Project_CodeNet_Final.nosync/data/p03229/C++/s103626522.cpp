#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,a,b) for(int64_t i=(a); i<(b); ++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int64_t i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define INF 1000000000000
#define MOD 1000000007LL
#define RANGE(a,b,c) (a).begin()+(b),(a).begin()+(c) // [b,c) イテレータ
typedef pair<int64_t, int64_t> PII;
typedef vector<int64_t> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;
typedef int64_t i64;

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

i64 N; cin >> N;
VI A(N); rep(i, 0, N) cin >> A[i];
sort(ALL(A));

i64 ans0 = 0, ans1 = 0;
if (N%2){
    rep(i, 0, N/2) ans0 -= 2 * A[i];
    rep(i, N/2, N/2 + 2) ans0 += A[i];
    rep(i, N/2 + 2, N) ans0 += 2 * A[i];

    rep(i, 0, N/2 - 1) ans1 -= 2 * A[i];
    rep(i, N/2 - 1, N/2 + 1) ans1 -= A[i];
    rep(i, N/2 + 1, N) ans1 += 2 * A[i];
}
else {
    ans0 = A[N/2] - A[N/2 - 1];
    rep(i, 0, N/2 - 1) ans0 -= 2 * A[i];
    rep(i, N/2 + 1, N) ans0 += 2 * A[i];
}

cout << max(ans0, ans1) << endl;

}
// 書いて考える．場合分け
// 境界，出力文字列 チェック
// 可読性優先．高速化次点．
// まずは全探索，分割統治，次にDP
// 制限を見る．境界に注意．求めたい量の変域．動かせる量．
// 偶奇，逆から，ソート，出現回数，出現位置，DP， 余事象，包除
// データ構造． 問題の特徴量．単調性，二分探索
// 存在判定：構成方法，入力の特徴
// gcd, lcm ,素因数分解．
// 例外を十分に含む一般化．想像力の限界
// 小さい系から例示
// 代数的処理．前処理によるクエリ高速化．
// 始めは過剰に例示・場合分けしてもいい．各場合を確実に対処．
// 自明な例から処理，除外．
// 小数のときは，精度の設定する．doubel 変数に数値を入力するときは 123. とする．
// テストケース作成は数表あり
// 実行エラー：vector添え字超え．0割り．

