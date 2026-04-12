#include <iostream>
#include <vector>
using namespace std;

#define W 5
#define H 5
#define N (W-1) * (H-1)

#define INF 1e9

int m[H][W];
int MaxScore2[5][5][5][5][5][5][5][5][5][5];
int MaxScore[5][5][5][5];

int GetScore(int x, int y) {
	switch (m[y][x]) {
		case -1: return 0;
		case 0: return 0;
		case 1: return 60;
		case 2: return 70;
		case 3: return 80;
	}
}

void click(int x, int y) {
	for (int dx = 0; dx < 2; ++dx) {
		for (int dy = 0; dy < 2; ++dy) {
			if (m[y+dy][x+dx] > -1) {
				m[y+dy][x+dx] = (m[y+dy][x+dx] + 1) % 4;
			}
		}
	}
}

int maximize(int x, int y) {
	int ret = -INF;
	for (int i = 0; i < 4; ++i) {
		int v = GetScore(x, y) + GetScore(x+1, y) + GetScore(x, y+1) + GetScore(x+1, y+1);
		ret = max(ret, v);
		click(x, y);
	}
	return ret;
}

int GetMaxScore(int a, int b, int c, int d) {
	if (MaxScore[a][b][c][d] == -INF) {
		int M = -INF;
		vector<int> v(4);
		v[0] = a-1;
		v[1] = b-1;
		v[2] = c-1;
		v[3] = d-1;

		for (int i = 0; i < 4; ++i) {
			int val = 0;
			for (int j = 0; j < 4; ++j) {
				if (v[j] > -1) {
					v[j] = (v[j] + 1) % 4;
					val += v[j] == 1 ? 60 : v[j] == 2 ? 70 : v[j] == 3 ? 80 : 0;
				}
			}
			M = max(M, val);
		}
		MaxScore[a][b][c][d] = M;
	}
	return MaxScore[a][b][c][d];
}

int CalcMaxScore(int x, int y) {
	return GetMaxScore(m[y][x]+1, m[y][x+1]+1, m[y+1][x]+1, m[y+1][x+1]+1);
}

int calc(int k) {
	int ret = -INF;
	if (k == 16) {
		ret = MaxScore2
			[m[0][0]+1]
			[m[0][1]+1]
			[m[1][0]+1]
			[m[1][1]+1]
			[m[2][0]+1]
			[m[2][1]+1]
			[m[3][0]+1]
			[m[3][1]+1]
			[m[4][0]+1]
			[m[4][1]+1];

		ret += MaxScore2
			[m[0][3]+1]
			[m[0][4]+1]
			[m[1][3]+1]
			[m[1][4]+1]
			[m[2][3]+1]
			[m[2][4]+1]
			[m[3][3]+1]
			[m[3][4]+1]
			[m[4][3]+1]
			[m[4][4]+1];

		for (int y = 0; y < H; ++y) ret += GetScore(2, y);
	}
	else {
		int x = k % 4, y = k / 4;
		if (x == 0 || x == 3) return calc(k+1);

//		int m2[H][W];
//		for (int y = 0; y < H; ++y) for (int x = 0; x < W; ++x) m2[y][x] = m[y][x];
		click(x, y); ret = max(ret, calc(k+1));
		click(x, y); ret = max(ret, calc(k+1));
		click(x, y); ret = max(ret, calc(k+1));
		click(x, y); ret = max(ret, calc(k+1));

//		for (int y = 0; y < H; ++y) for (int x = 0; x < W; ++x) if (m2[y][x] != m[y][x]) cout << "e" << endl;
	}
	return ret;
}

int m2[5][2];
int CalcMaxScore2(int x, int y) {
	return GetMaxScore(m2[y][x]+1, m2[y][x+1]+1, m2[y+1][x]+1, m2[y+1][x+1]+1);
}
void click2(int x, int y) {
	for (int dx = 0; dx < 2; ++dx) {
		for (int dy = 0; dy < 2; ++dy) {
			if (m2[y+dy][x+dx] > -1) {
				m2[y+dy][x+dx] = (m2[y+dy][x+dx] + 1) % 4;
			}
		}
	}
}
int GetScore2(int x, int y) {
	switch (m2[y][x]) {
		case -1: return 0;
		case 0: return 0;
		case 1: return 60;
		case 2: return 70;
		case 3: return 80;
	}
}
int calc2(int k) {
	int ret = -INF;
	if (k == 5) {
		ret = 0;

		int x = 0;
		for (int y = 0; y < 4; ++y) {
			if (y % 2 == 0) ret += CalcMaxScore2(x, y);
		}

		ret += GetScore2(0, 4);
		ret += GetScore2(1, 4);
	}
	else {
		int x = 0, y = k;
		for (int i = 0; i < 4; ++i) {
			click2(x, y); ret = max(ret, calc2(k+2));
		}
	}
	return ret;
}
void makeM2(int k) {
	if (k == 10) {
		MaxScore2
			[m2[0][0]+1]
			[m2[0][1]+1]
			[m2[1][0]+1]
			[m2[1][1]+1]
			[m2[2][0]+1]
			[m2[2][1]+1]
			[m2[3][0]+1]
			[m2[3][1]+1]
			[m2[4][0]+1]
			[m2[4][1]+1]
				= calc2(1);
	}
	else {
		int x = k % 2, y = k / 2;
		for (int i = -1; i < 4; ++i) {
			m2[y][x] = i;
			makeM2(k+1);
		}
	}
}

int main() {
	for (int a = 0; a < 5; ++a) for (int b = 0; b < 5; ++b) for (int c = 0; c < 5; ++c) for (int d = 0; d < 5; ++d) MaxScore[a][b][c][d] = -INF;
	makeM2(0);

	int n; cin >> n;
	for (int t = 0; t < n; ++t) {
		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {
				cin >> m[y][x];
				--m[y][x];
			}
		}

		cout << calc(0) << endl;
	}
}