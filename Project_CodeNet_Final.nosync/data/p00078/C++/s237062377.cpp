#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	int n, **ms;
	while (cin >> n && n) {
		ms = new int*[n];
		for (int i = 0; i < n; i++)
			ms[i] = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ms[i][j] = 0;

		int x = n / 2;
		int y = x + 1;
		ms[y][x] = 1;
		for (int i = 2; i <= n * n; i++) {
			x++; y++;
			while (1) {
				if (n <= x)
					x = 0;
				else if (x < 0)
					x = n - 1;
				else if (n <= y)
					y = 0;
				else if (y < 0)
					y = n - 1;
				else if (ms[y][x] != 0) {
					x--;
					y++;
				}
				else {
					ms[y][x] = i;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%4d", ms[i][j]);
//				cout << setprecision(2) << ms[i][j];
			cout << endl;
		}

		for (int i = 0; i < n; i++)
			delete[] ms[i];
		delete[] ms;
	}
	return 0;
}