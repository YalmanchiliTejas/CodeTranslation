//大文字->小文字 tolower(),逆はtoupper()
//int a = stoi(c); 文字列をintへ
//途中の出力をそのまま残さない
//数値計算 基本はdouble
//map<キー,値> p は辞書。p[キー] = 値
#include <bits/stdc++.h>
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
	int X; cin >> X;
	if (X == 3 || X == 5 || X == 7)cout << "YES" << endl;
	else cout << "NO" << endl;
}