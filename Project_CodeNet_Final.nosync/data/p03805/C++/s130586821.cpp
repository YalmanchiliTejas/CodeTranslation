#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <time.h>
#include <stdio.h>
#define int long long
using namespace std;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
int mypow(int x, int y) {
	if (y == 0)return 1;
	if (y % 2)return mypow(x, y - 1)*x;
	else return mypow(x, y / 2)*mypow(x, y / 2);
}
int Max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int Min(int x, int y) {
	if (x < y)return x;
	else return y;
}
/*ライブラリゾーン！！！！！！！！！！！！！！！*/
int n, m, a, b,ans,o[10],michi[10][10];
signed main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		michi[a][b] = michi[b][a] = 1;
	}
	for (int i = 0; i < n; i++)o[i] = i + 1;
	do {
		for (int i = 1; i < n; i++) {
			if (michi[o[i - 1]][o[i]] == 0)goto bed;
		}
		ans++;
	bed:;
	} while (next_permutation(o + 1, o + n));
	cout << ans << endl;
end:;
	system("PAUSE");
	return 0;
}
