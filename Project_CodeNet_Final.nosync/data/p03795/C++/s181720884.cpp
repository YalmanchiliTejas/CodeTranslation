//int a = stoi(c); 文字列をintへ
//小文字から大文字
//transform(a.begin(), a.end(), a.begin(), ::toupper);
//途中の出力をそのまま残さない
//数値計算 個数以外はdouble
//map<キー,値> p は辞書。p[キー] = 値
//map 全探索
//auto begin = p.begin(), end = p.end();
//for (auto it = begin; it != end; it++) {}
//mapのキー：it->first mapのバリュー：it->second
//絶対値 abs()
//入力は空白で切れる
//大文字判定 isupper(文字) 小文字判定 islower(文字)
//do{}while(next_permutation(ALL(配列)))
//while(N)で回すとき、Nはコピーを作っておく
//小文字に対応する文字コード：S[i] - 'a'
//文字コード→小文字：(char)(数字+'a')
//グラフの距離:隣接行列で扱う
//等価なものに変換する思考
//bool型　初期値はTrue
//島渡りの問題：中間ノードに着目
//配列はvector<>を使う：意味わからないエラーがなくなる。
//背反な事象にちゃんとわける
//チェックリストはマップを使う
//数が大きい時の比較はstring型で行う
//全て0になったか調べたい->0になるたびにcntする
#include <bits/stdc++.h>
#define rep(i,N) for(int i = 0; i < N;i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long int
using namespace std;

// K進数でのNの桁数
ll dig(ll N, ll K) {
	ll dig = 0;
	while (N) {
		dig++;
		N /= K;
	}
	return dig;
}
// a,bの最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

//nC2の計算
ll C(ll N) {
	return N * (N - 1) / 2;
}

//円周率
const double PI = 3.14159265358979323846;

int main() {
	int N; cin >> N;

	cout << 800 * N - 200 * (N / 15) << endl;
}