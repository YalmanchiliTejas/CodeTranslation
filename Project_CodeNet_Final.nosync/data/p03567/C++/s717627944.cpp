#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
//---------------------------------------------------
//ライブラリゾーン！！！！
#define int long long
#define str string
#define rep(i,j) for(int i=0;i<(int)(j);i++)
typedef long long ll;
typedef long double ld;
const ll inf = 4523372036854775807;
short gh[2][4] = { { 0,0,-1,1 },{ -1,1,0,0 } };
struct P {
	ll pos, cost;
};
bool operator<(P a, P b) { return a.cost < b.cost; }
bool operator>(P a, P b) { return a.cost > b.cost; }
struct B {//隣接リスト表現
	ll to, cost;
};
struct S {//辺の情報を入れる変数
	int from, to, cost;
};
struct H {
	int x, y;
};
bool operator<(H a, H b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool operator>(H a, H b) {
	if (a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}
ll gcm(ll i, ll j) {//最大公約数
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcm(j%i, i);
}
ld rad(ld a, ld b, ld c, ld d) {
	return sqrt(pow(a - c, 2) + pow(b - d, 2));
}//rad＝座標上の2点間の距離
int ari(int a, int b, int c) {
	return (a + b)*c / 2;
}//等差数列の和
bool suf(ld a, ld b, ld c, ld d) {
	if (b <= c || d <= a) return 0;
	return 1;
}//[a,b),[c,d)
//---------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++
signed main() {
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == 'A'&&s[i] == 'C') {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	getchar(); getchar();
}