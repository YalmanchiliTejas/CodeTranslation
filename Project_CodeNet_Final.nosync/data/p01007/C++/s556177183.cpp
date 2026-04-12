#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > data(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	for (int i = 0; i < m; i++) {
		int o;
		cin >> o;
		if (o == 0) {
			int r, c, s, a;
			cin >> r >> c >> s >> a;
			r--;
			c--;
			vector< vector<int> > data2(s, vector<int>(s));
			if (a == 90) {
				for (int j = 0; j < s; j++) {
					for (int k = 0; k < s; k++) {
						data2[j][k] = data[r+s-1-k][c+j];
					}
				}
			} else if (a == 180) {
				for (int j = 0; j < s; j++) {
					for (int k = 0; k < s; k++) {
						data2[j][k] = data[r+s-1-j][c+s-1-k];
					}
				}
			} else if (a == 270) {
				for (int j = 0; j < s; j++) {
					for (int k = 0; k < s; k++) {
						data2[j][k] = data[r+k][c+s-1-j];
					}
				}
			} else {
				for (int j = 0; j < s; j++) {
					for (int k = 0; k < s; k++) {
						data2[j][k] = data[j+r][k+c];
					}
				}
			}
			for (int j = 0; j < s; j++) {
				for (int k = 0; k < s; k++) {
					data[j+r][k+c] = data2[j][k];
				}
			}
		} else if (o == 1) {
			int r, c, s;
			cin >> r >> c >> s;
			r--;
			c--;
			for (int j = r; j < r+s; j++) {
				for (int k = c; k < c+s; k++) {
					data[j][k] = 1 - data[j][k];
				}
			}
		} else if (o == 2) {
			int r;
			cin >> r;
			r--;
			int kari = data[r][0];
			for (int j = 0; j < n-1; j++) {
				data[r][j] = data[r][j+1];
			}
			data[r][n-1] = kari;
		} else if (o == 3) {
			int r;
			cin >> r;
			r--;
			int kari = data[r][n-1];
			for (int j = n-1; j > 0 ; j--) {
				data[r][j] = data[r][j-1];
			}
			data[r][0] = kari;
		} else {
			int r, c;
			cin >> r >> c;
			r--;
			c--;
			int k = data[r][c];
			data[r][c] = 1 - k;
			vector< vector<int> > data2(n, vector<int>(n, 0));
			data2[r][c] = 1;
			queue<P> q;
			q.push(P(r, c));
			while (!q.empty()) {
				P p = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					if (p.first+dx[i] >= 0 && p.first+dx[i] < n && p.second+dy[i] >= 0 && p.second+dy[i] < n) {
						if (data2[p.first+dx[i]][p.second+dy[i]] == 0 && data[p.first+dx[i]][p.second+dy[i]] == k) {
							data[p.first+dx[i]][p.second+dy[i]] = 1-k;
							data2[p.first+dx[i]][p.second+dy[i]] = 1;
							q.push(P(p.first+dx[i], p.second+dy[i]));
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				cout << data[i][j];
			} else {
				cout << ' ' << data[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}