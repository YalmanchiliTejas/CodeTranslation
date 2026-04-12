#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_N 100

int x[MAX_N][MAX_N];
int Q, n;
int y[MAX_N][MAX_N];
int z[MAX_N][MAX_N];

void Rotate(int a, int b, int c, int d) {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			y[i][j] = 0;
			z[i][j] = 0;
		}
	}
	for (int i = a; i < a + c; i++) {
		for (int j = b; j < b + c; j++) {
			y[i - a][j - b] = x[i][j];
		}
	}
	for (int i = 0; i < d / 90; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < c; k++) {
				z[k][c - 1 - j] = y[j][k];
			}
		}
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < c; k++) {
				y[j][k] = z[j][k];
			}
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			x[i + a][j + b] = y[i][j];
		}
	}
}

void Reversal(int a, int b, int c) {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			y[i][j] = 0;
			z[i][j] = 0;
		}
	}
	for (int i = a; i < a + c; i++) {
		for (int j = b; j < b + c; j++) {
			y[i - a][j - b] = x[i][j];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if (y[i][j] == 0) {
				y[i][j] = 1;
			}
			else {
				y[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			x[i + a][j + b] = y[i][j];
		}
	}
}

void Left_Shift(int a) {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			y[i][j] = 0;
			z[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		y[0][i] = x[a][i];
	}
	for (int i = 2; i <= n; i++) {
		z[0][i - 1] = y[0][i];
	}
	z[0][n] = y[0][1];
	for (int i = 1; i <= n; i++) {
		y[0][i] = z[0][i];
	}
	for (int i = 1; i <= n; i++) {
		x[a][i] = y[0][i];
	}
}

void Right_Shift(int a) {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			y[i][j] = 0;
			z[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		y[0][i] = x[a][i];
	}
	for (int i = 1; i <= n - 1; i++) {
		z[0][i + 1] = y[0][i];
	}
	z[0][1] = y[0][n];
	for (int i = 1; i <= n; i++) {
		y[0][i] = z[0][i];
	}
	for (int i = 1; i <= n; i++) {
		x[a][i] = y[0][i];
	}
}

void Island_Reversal(int a, int b) {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			y[i][j] = 0;
			z[i][j] = 0;
		}
	}
	queue<pair<int, int>>Q;
	while (!Q.empty()) { Q.pop(); }
	Q.push(make_pair(a, b));
	y[a][b] = 1;
	while (!Q.empty()) {
		pair<int, int>q = Q.front(); Q.pop();
		int c = q.first; int d = q.second;
		if (c >= 2) {
			if (x[c][d] == x[c - 1][d] && y[c - 1][d] == 0) {
				Q.push(make_pair(c - 1, d));
				y[c - 1][d] = 1;
			}
		}
		if (d >= 2) {
			if (x[c][d] == x[c][d - 1] && y[c][d - 1] == 0) {
				Q.push(make_pair(c, d - 1));
				y[c][d - 1] = 1;
			}
		}
		if (c < n) {
			if (x[c][d] == x[c + 1][d] && y[c + 1][d] == 0) {
				Q.push(make_pair(c + 1, d));
				y[c + 1][d] = 1;
			}
		}
		if (d < n) {
			if (x[c][d] == x[c][d + 1] && y[c][d + 1] == 0) {
				Q.push(make_pair(c, d + 1));
				y[c][d + 1] = 1;
			}
		}
	}
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			if (y[i][j] == 1) {
				if (x[i][j] == 0) {
					x[i][j] = 1;
				}
				else {
					x[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		int E1 = 0, E2 = 0, E3 = 0, E4 = 0, E5 = 0;
		cin >> E1;
		if (E1 == 0) {
			cin >> E2 >> E3 >> E4 >> E5;
			Rotate(E2, E3, E4, E5);
		}
		if (E1 == 1) {
			cin >> E2 >> E3 >> E4;
			Reversal(E2, E3, E4);
		}
		if (E1 == 2) {
			cin >> E2;
			Left_Shift(E2);
		}
		if (E1 == 3) {
			cin >> E2;
			Right_Shift(E2);
		}
		if (E1 == 4) {
			cin >> E2 >> E3;
			Island_Reversal(E2, E3);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= 2) {
				cout << ' ';
			}
			cout << x[i][j];
		}
		cout << endl;
	}
	return 0;
}