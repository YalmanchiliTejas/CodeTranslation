#include <bits/stdc++.h>

//#define int long long

using namespace std;

int d[101][101];
char a[101][101];

int main () {
	int n, m;
	cin >> n >> m;
	int kol = 0;
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= m;j ++) {
			cin >> a[i][j];
			if (a[i][j] == '#') kol ++;
		}
	}
	if (kol != n + m - 1) {	cout << "Impossible"; return 0;}
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= m;j ++) {
			if (a[i + 1][j] == '#' && a[i][j + 1] == '#') {	cout << "Impossible"; return 0;}
		}
	}
	cout << "Possible";
    return 0;           		
}