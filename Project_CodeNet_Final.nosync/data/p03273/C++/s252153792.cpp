#include "bits/stdc++.h"
using namespace std;

/*第二引数で第一引数を割ったときの切り上げの計算*/
long long int maxtime(long long int x, long long int y) {
	return(x + y - 1) / y;

}
/*最大公約数*/
long long int lcm(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;

	if (number2 > number1) {
		m = number2;
		n = number1;
	}
	long long int s = -1;
	while (s != 0) {
		s = m % n;
		m = n;
		n = s;
	}
	return m;
}
/*最大公倍数*/
long long int gcd(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;
	return m / lcm(m, n) * n;
}
int main() {
	vector<vector<char>> c(120);
	int H, W;
	cin >> H >> W;
	int sumh = 0;
	int sumw = 0;
	int sumhh[200] = {};
	int sumww[200] = {};
	for (int i = 0; i < H; i++) {
		int k = 0;
		for (int j = 0; j < W; j++) {
			char a;
			cin >> a;
			c[i].push_back(a);
			if (a == '.') {
				k++;
			}
		}
		if (k == W) {
			sumh++;
			sumhh[i] = 1;
		}
	}
	for (int i = 0; i < W; i++) {
		int k = 0;
		for (int j = 0; j < H; j++) {
			char a = c[j][i];
			if (a == '.') {
				k++;
			}
		}
		if (k == H ) {
			sumw++;
			sumww[i] = 1;

		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!(sumhh[i] == 1 || sumww[j] == 1)) {
				cout << c[i][j];
			}
		}
		if (!(sumhh[i] == 1)){
			cout << "\n";
		}
	}
}