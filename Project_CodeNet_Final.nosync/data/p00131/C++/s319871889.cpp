#include <bits/stdc++.h>

using namespace std;

int OriginalData[10][10], Ans[10][10], Tmp[10][10];
int Used[10];

bool judge() {
	int dx[] = { 0,-1,0,1,0 };
	int dy[] = { -1,0,0,0,1 };
	int currentX, currentY;

	memset(Ans, 0, sizeof(Ans));
	memcpy(Tmp, OriginalData, sizeof(Tmp));

	for (int j = 0; j < 10; j++) {
		Ans[0][j] = Used[j];
		if (Used[j]) {
			for (int k = 0; k < 5; k++) {
				currentX = dx[k];
				currentY = j + dy[k];

				if (currentX<0 || currentX>9 || currentY<0 || currentY>9) {
					continue;
				}
				Tmp[currentX][currentY] = !Tmp[currentX][currentY];
			}
		}
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Tmp[i - 1][j]) {
				Ans[i][j] = 1;
				for (int k = 0; k < 5; k++) {
					currentX = i + dx[k];
					currentY = j + dy[k];

					if (currentX<0 || currentX>9 || currentY<0 || currentY>9) {
						continue;
					}
					Tmp[currentX][currentY] = !Tmp[currentX][currentY];
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Tmp[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool solve(int col) {
	if (col == 10) {
		if (judge()) {
			return true;
		}
		return false;
	}

	if (solve(col + 1)) {
		return true;
	}
	Used[col] = 1;
	if (solve(col + 1)) {
		return true;
	}
	Used[col] = 0;
	
	return false;
}

int main() {
	int n;

	cin >> n;
	while (n--) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> OriginalData[i][j];
			}
		}
		memset(Used, 0, sizeof(Used));
		solve(0);

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << Ans[i][j] << (j == 9 ? "\n" : " ");
			}
		}
	}

	return 0;
}
