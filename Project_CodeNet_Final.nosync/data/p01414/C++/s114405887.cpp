#include "bits/stdc++.h"
using namespace std;
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2297&lang=jp
typedef long long ll;
typedef pair<int, int> pii;
int N;
vector<vector<int>> st;
vector<pii> rec;
int b1[16][3][55];
int b2[16][3][55];

void stamp_stete_check() {
	for (int n = 0; n < N;n++) {
		cout << "[" << rec[n].first << "," << rec[n].second << "]" << endl;
		for (int i = 0; i < st[n].size();i++) {
			for (int j = 0; j < 16;j++) {
				if (j % 4 == 0) cout << endl;
				if (st[n][i] & (1 << j)) {
					cout << "o";
				}
				else {
					cout << "x";
				}
			}
			cout << endl;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	/* input */
	cin >> N;
	rec.resize(N);
	st.resize(N);
	for (int n = 0; n < N;n++) {
		int H, W; cin >> H >> W;
		rec[n] = { H,W };
		for (int i = -3; i < 4;i++) {
			for (int j = -3; j < 4;j++) {
				int s = 0;
				for (int h = max(0,i); h < min(4, i + H);h++) {
					for (int w = max(0,j); w < min(4, j + W);w++) {
						s += (1 << (4 * h + w));
					}
				}
				if (s == 0)continue;
				st[n].push_back(s);
			}
		}
	}

	// stamp_stete_check();

	/* Classification */
	vector<int> m(16);
	for (int i = 0; i < 16;i++) {
		char c; cin >> c;
		if (c == 'R') m[i] = 0;
		else if (c == 'G') m[i] = 1;
		else m[i] = 2;
	}

	/* Preprocessing */
	for (int n = 0; n < N;n++) {
		for (int c = 0; c < 3;c++) {
			for (int i = 0; i < st[n].size();i++) {
				int B1, B2; B1 = B2 = 0;
				for (int b = 0; b < 16;b++) {
					if (~st[n][i] & (1 << b)) continue;
					if (c == m[b]) {
						B1 += (1 << b);
					}
					else {
						B2 += (1 << b);
					}
				}
				b1[n][c][i] = B1;
				b2[n][c][i] = B2;
			}
		}
	}

	/* initialize */
	vector<int> memo(1 << 16, -1);
	queue<int> q;
	q.push(0);
	memo[0] = 0;

	/* bfs */
	while (!q.empty()) {
		int n = q.front(); q.pop();
		for (int i = 0; i < 16;i++) {
			if (n & (1 << i))continue;
			int v = m[i];
			for (int j = 0; j < N;j++) {
				for (int k = 0; k < st[j].size(); k++) {
					if (~st[j][k] & (1 << i)) continue;	
					int next = n;

					next = next | b1[j][v][k];
					next = next & ~b2[j][v][k];

					if (memo[next] != -1)continue;
					memo[next] = memo[n] + 1;
					if (next == ((1 << 16) - 1)) {
						cout << memo[next] << endl;
						return 0;
					}
					q.push(next);
				}
			}
		}
	}
	return 0;
}