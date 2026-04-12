#include <bits/stdc++.h>
using namespace std;

int main() {
	//入力
	int r, g, b;
	cin >> r >> g >> b;
	
	//処理
	int ans = (r * 100) + (g * 10) + b;
	if (ans % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}