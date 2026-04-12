#include<iostream>

using namespace std;

int n, m, k, p;
char a[10000][10000];
int b[10000];

int main() {
	for (int i = 0; i < 10000; i++)b[i] = 100;
	cin >> n >> m;
	p = 0;

	for (int i = 0; i < n; i++) {
		k = 0;
		cin >> a[p];
		for (int j = 0; j < m; j++) {
			if (a[p][j] == '.')k++;
		}
		if (k == m)p--;
		p++;
	}
	n = p;
	
	p = 0;
	for (int j = 0; j < m; j++) {
		k = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == '.')k++;
		}
		if (k == n) {
			b[p] = j;
			p++;
		}
	}
	for (int i = 0; i < n; i++) {
		p = 0;
		for (int j = 0; j < m; j++) {
			if (b[p] != j) {
				cout << a[i][j];
			}
			else {
				p++;
			}
		}
		cout << '\n';
	}
	cin >> n;
	return 0;

}