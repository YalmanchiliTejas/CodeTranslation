#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
//もう二度とつかわん//
//    ↓ ↓　↓　　 //
#define ll long long
//    ↑　↑　↑    //
//フェルマー方程式の恨み//
#define rep(i,n) for(int i=0;i<n;i++)
#define ggr getchar(); getchar();return 0;
using namespace std;
//素数判定
bool prime(ll n) {
	if (n == 1)return false;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
char a[114][114];
signed main() {
	ll h, w;
	cin >> h >> w;
	rep(i, h) { rep(j, w)cin >> a[i][j]; }
	bool b[114], c[114];
	rep(i, 114) {
		b[i] = true, c[i] = true;
	}
	rep(i, h) {
		rep(j, w) {
				if (a[i][j] == '#')b[i] = false;
		}
	}
	rep(i, w) {
		rep(j, h) {
				if (a[j][i] == '#')c[i] = false;
		}
	}
	rep(i, h) {
		if (!b[i]) {
			rep(j, w) {
				if (!c[j])cout << a[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;
	ggr
}
