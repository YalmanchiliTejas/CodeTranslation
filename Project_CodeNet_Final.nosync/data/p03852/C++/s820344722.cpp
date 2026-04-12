//大文字->小文字 tolower(),逆はtoupper()
//int a = stoi(c); 文字列をintへ
//途中の出力をそのまま残さない
//数値計算 個数以外はdouble
//map<キー,値> p は辞書。p[キー] = 値
//絶対値 abs()
//入力は空白で切れる
//大文字判定 isupper(文字) 小文字判定 islower(文字)
#include <bits/stdc++.h>
#define rep(i,N) for(int i = 0; i < N;i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long int
using namespace std;

// Nの桁数
ll dig(ll N) {
	ll dig = 0;
	while (N) {
		dig++;
		N /= 10;
	}
	return dig;
}
// x,yの最大公約数
ll gcd(ll x, ll y) {
	ll r;
	while (x%y) {
		r = x % y;
		x = y;
		y = r;
	}
	return y;
}

int main() {
	char c; cin >> c;
	if (c != 'a' &&c != 'i' &&c != 'u' &&c != 'e' &&c != 'o') {
		cout << "consonant" << endl;
		return 0;
	}
	cout << "vowel" << endl;
}