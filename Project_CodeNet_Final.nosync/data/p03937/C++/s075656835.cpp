#include <iostream>
using namespace std;

const int N = 10;

char c[N][N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		} 
	}
	bool b = true;
	for (int i1 = 1; i1 <= n; i1++) {
		for (int j1 = 1; j1 <= m; j1++) {
			for (int i2 = 1; i2 <= n; i2++) {
				for (int j2 = 1; j2 <= m; j2++) {
					if ((c[i1][j1] == '#' && c[i2][j2] == '#') && ((i1 > i2 && j1 < j2) || (i1 < i2 && j1 > j2))) {
						b = false;
					//	cout << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
					}
				}
			}
		}
	}
	if (b)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}
