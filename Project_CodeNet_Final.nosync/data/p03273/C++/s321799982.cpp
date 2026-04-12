#include <iostream>
#include <string>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int h, w;
char a[100][101];
char b[100][101];
char c[100][101];

int main() {
	int i, j;
	int cor;
	
	cin >> h >> w;
	rep(i, h) cin >> a[i];
	
	cor = 0;
	rep(i, h) {
		rep(j, w) if (a[i][j] == '#') break;
		if (j == w) continue;
		rep(j, w) b[cor][j] = a[i][j];
		cor++;
	}
	int row = cor;
	
	cor = 0;
	rep(j, w) {
		rep(i, row) if (b[i][j] == '#') break;
		if (i == row) continue;
		rep(i, row) c[i][cor] = b[i][j];
		cor++;
	}
	int col = cor;
	
	rep(i, row) {
		rep(j, col) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}
