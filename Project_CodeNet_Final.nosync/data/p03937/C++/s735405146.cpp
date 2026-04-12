#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<iomanip>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
char a[9][9];
signed main() {
	ll h, w, cnt = 0;
	cin >> h >> w;
	rep(i, h) { rep(j, w)cin >> a[i][j]; }
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] == '#')cnt++;
		}
	}
	if (cnt == h + w - 1)puts("Possible");
	else puts("Impossible");
	getchar(); getchar(); return 0;
}