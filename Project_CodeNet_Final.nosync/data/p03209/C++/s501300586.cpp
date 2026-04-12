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

VI len, numP;

i64 f(i64 n, i64 x){
    if (n == 0)
        return ((x <= 0) ? 0 : 1);
    else if (x <= 1 + len[n - 1])
        return f(n - 1, x - 1);
    else 
        return numP[n - 1] + 1 + f(n - 1, x - 2 - len[n - 1]);
}

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

i64 N, X; cin >> N >> X;

len.assign(N+1, 1);
numP.assign(N+1, 1);

rep(i, 1, N+1){
    len[i] = 2 * len[i - 1] + 3;
    numP[i] = 2 * numP[i - 1] + 1;
}

cout << f(N, X) << endl;

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

