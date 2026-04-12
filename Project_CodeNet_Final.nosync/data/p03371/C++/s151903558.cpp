#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>

using namespace std;

int X; //Aの枚数
int Y; //B
int Z; //AB

int get_max(int *X, int *Y) {
	int max = 0;
	if (*X > *Y) {
		max = *X;
	}
	else {
		max = *Y;
	}
	return max;
}

int main() {
	int a, b, c = 0; //ピッツァの価格
	int ans = 0;

	cin >> a >> b >> c >> X >> Y;
	//ハーフを入れて買うのがお得な時(ABの値段の2倍がA,Bの和を超えないとき)
	if ((a + b) > c * 2) {
		int max;
		max = get_max(&X, &Y);

		int tmp = max * 2 * c;
		while (X>0 && Y>0) {
			X = X - 1;
			Y = Y - 1;
			Z = Z + 2;
		}
		ans = c * Z + a * X + b * Y;
		if (ans > tmp) {
			ans = tmp;
		}
	}
	//ハーフを入れて買わない時
	else {
		ans = a * X + b * Y;
	}

	cout << ans << endl;
	return 0;
}