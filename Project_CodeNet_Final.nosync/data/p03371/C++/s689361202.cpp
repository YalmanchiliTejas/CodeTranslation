#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	//入力
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;

	int ans = INT_MAX;
	for (int ACnt = 0;ACnt <= x;++ACnt) {
		//ABの枚数
		int ABCnt = (x - ACnt) * 2;
		//Bの枚数
		int BCnt = max(0,y - ABCnt / 2);
		ans = min(ans, ACnt * a + BCnt * b + ABCnt * c);
	}
	for (int BCnt = 0;BCnt <= y;++BCnt) {
		//ABの枚数
		int ABCnt = (y - BCnt) * 2;
		//Aの枚数
		int ACnt = max(0, x - ABCnt / 2);
		ans = min(ans, ACnt * a + BCnt * b + ABCnt * c);
	}

	//答え
	std::cout << ans << endl;
}