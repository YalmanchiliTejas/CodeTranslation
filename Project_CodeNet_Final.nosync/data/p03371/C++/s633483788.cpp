#include <bits/stdc++.h>
using namespace std;
int f(int x, int y, int z) {
	return x * x + y * y + z * z + x * y + y * z + z * x;
}

int main() {
	int a, b, c, x, y,ans;
	cin >> a >> b >> c >> x >> y;
	if (a + b > 2*c) {//a,b1枚ずつ買う方がABを組み替えて1枚づつにするより高い場合
		int tmp1, tmp2,tmp,dai;
		if (x >= y) {
			tmp1 = 2 * c * y + a * (x - y);
			tmp2 = 2 * c * x;
		}
		else {
			tmp1 = 2 * c * x + b * (y - x);
			tmp2 = 2 * c * y;
		}
		ans = min(tmp1, tmp2);
	}
	else {
		ans = a * x + b * y;
	}
	cout << ans << endl;
	
}