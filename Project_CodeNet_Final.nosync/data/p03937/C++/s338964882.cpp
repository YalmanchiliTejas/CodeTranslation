#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, cnt;
char map[10][10];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') cnt++;
		}
	}
	if (n + m - 1 == cnt) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	
	return 0;
}