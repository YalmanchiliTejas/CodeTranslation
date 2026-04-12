#include<iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int m[17][17] = {};
		m[n/2+1][n/2] = 1;
		int px = n/2+1;
		int py = n /2;
		for (int i = 2;i <= n*n;i++) {
			px++;
			py++;
			if (px >= n)px -= n;
			if (py >= n)py -= n;
			if (m[px][py] != 0) {
				px++;
				py--;
				if (py < 0)py += n;
				if (px >= n)px -= n;
			}
			m[px][py] = i;
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				printf("%4d", m[i][j]);
				if (j == n - 1)cout << endl;
			}
		}
	}
	return 0;
}