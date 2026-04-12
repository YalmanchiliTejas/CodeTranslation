#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
	string a;
	while (cin >> a&&a != "#") {
		char h[9][9];
		int sum = 0;
		int b[2] = { 0,0 };
		for (int i = 0; i < a.length(); i++) {
			if (a[i] =='/') {
				b[0]++;
				b[1] = 0;
			}
			else {
				if (a[i] >= '0'&&a[i] <= '9') {
					int e = a[i] - '0';
					for (int j = b[1]; j < b[1] + e; j++) {
						h[b[0]][j] = '.';
					}
					b[1] += e;
				}
				else {
					h[b[0]][b[1]] = 'b';
					b[1]++;
				}
			}
		}
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;
		x--;
		y--;
		x2--;
		y2--;
		h[x][y] = '.';
		h[x2][y2] = 'b';
		for (int i = 0; i <= b[0]; i++) {
			int sum = 0;
			for (int j = 0; j < b[1]; j++) {
				if (h[i][j] == '.') sum++;
				else {
					if (sum != 0) {
						cout << sum;
						sum = 0;
					}
					cout << 'b';
				}
			}
			if (sum != 0) cout << sum;
			if(i!=b[0])cout << '/';
		}
		cout << endl;
	}
}