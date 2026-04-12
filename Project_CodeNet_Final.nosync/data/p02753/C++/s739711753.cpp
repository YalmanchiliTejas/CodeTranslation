#include <iostream>
#include <cmath>
#include <algorithm>
#include <string> //文字列
#include <iomanip> //doubleの桁数指定

#define REP(i,m,n) for(int i = (int) (m);i < (int) (n);i++) //forの短縮
#define rep(i,n) REP(i,0,n) //REPが0の時
#define ll long long int

using namespace std;

double PI = 3.141592653589793; //円周率

//常設関数↓

//最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

//最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

//degree → radian
ll chg_DegRad(int deg) {
	return deg * PI / 180.0;
}

//radian → degree
ll chg_RadDeg(int rad) {
	return rad * 180.0 / PI;
}

//提出コード↓

string S;
bool a = false;
bool b = false;


int main() {

	cin >> S;
	rep(i, 3) {
		if (S[i] == 'A') a = true;
		if (S[i] == 'B') b = true;
	}
	if (a && b) cout << "Yes" << endl;
	else cout << "No" << endl;




	return 0;
}

