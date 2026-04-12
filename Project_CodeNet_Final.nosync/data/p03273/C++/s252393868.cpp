#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100+5;

int h,w;
char c[maxn][maxn];
bool fh[maxn];
bool fw[maxn];

void solve() {
	for (int i = 1; i <= h; i++) {
		bool flag = true;
		for (int j = 1; j <= w; j++) {
			if (c[i][j] == '#') {
				flag = false;
				break;
			}
		}
		if (flag) fh[i] = true;
	}
	for (int j = 1; j <= w; j++) {
		bool flag = true;
		for (int i = 1; i <= h; i++) {
			if (c[i][j] == '#') {
				flag = false;
				break;
			}
		}
		if (flag) fw[j] = true;
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (fh[i] || fw[j]) continue;
			cout << c[i][j];
		}
		if (!fh[i]) cout << endl;
	}
}

int main() {
	scanf("%d%d",&h,&w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++){
			cin >> c[i][j];
		}
	}
	solve();
	return 0;
}