#include <bits/stdc++.h>

using namespace std;

int d[11][11], f[111][111];
int main()
{
	int a, b, e = 0;
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			cin >> d[i][j];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 1; k <= a; k++)
				for (int l = 1; l <= b; l++)
					f[i][j] = max(f[i][j], d[k][l] - k * i - l * j);
			if (f[i][j] <= 100)
				e++;
		}
	}
	for (int k = 1; k <= a; k++) {
		for (int l = 1; l <= b; l++) {
			int m = 114514;
			for (int i = 0; i < 101; i++)
				for (int j = 0; j < 101; j++)
					m = min(m, f[i][j] + k * i + l * j);
			if (m != d[k][l]) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible\n202 " << e + 200 << "\n";
	for (int i = 0; i < 100; i++) {
		cout << i + 1 << ' ' << i + 2 << " X\n";
		cout << i + 102 << ' ' << i + 103 << " Y\n";
	}
	for (int i = 1; i < 102; i++)
		for (int j = 102; j < 203; j++)
			if (f[i - 1][202 - j] <= 100)
				cout << i << ' ' << j << ' ' << f[i - 1][202 - j] << '\n';
	cout << "1 202" << endl;
	return 0;
}
