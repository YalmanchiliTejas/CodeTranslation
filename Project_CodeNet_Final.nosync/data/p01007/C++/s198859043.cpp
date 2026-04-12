#include "bits/stdc++.h"
using namespace std;

const int adx[4] = { -1,0,1,0 };
const int ady[4] = { 0,1,0,-1 };

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>>field(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> field[i][j];
		}
	}
	while (M--) {
		int type; cin >> type;
		if (type == 0) {
			int r, c, s, a; cin >> r >> c >> s >> a;
			r--; c--;
			a /= 90;
			for (int i = 0; i < a; ++i) {
				vector<vector<int>>nfield(field);
				
				for (int dx = 0; dx <  s; ++dx) {
					for (int dy = 0; dy < s; ++dy) {
						nfield[r + dy][c + dx] = field[r+s-dx - 1 ][c+dy ];
					}
				}
				field = nfield;
			}
		}
		else if (type == 1) {
			int r, c, s; cin >> r >> c >> s;
			r--; c--;
			{
				vector<vector<int>>nfield(field);

				for (int dx = 0; dx < s; ++dx) {
					for (int dy = 0; dy < s; ++dy) {
						nfield[r + dy][c + dx] = !field[r+dy ][c+dx];
					}
				}
				field = nfield;
			}
		}
		else if (type == 2) {
			int r;
			cin >> r;
			r--; 
			{
				vector<vector<int>>nfield(field);

				rotate(nfield[r].begin(), nfield[r].begin() + 1, nfield[r].end());
				field = nfield;
			}
		}
		else if (type == 3) {
			int r;
			cin >> r;
			r--;
			{
				vector<vector<int>>nfield(field);

				rotate(nfield[r].begin(), nfield[r].begin() + N-1, nfield[r].end());
				field = nfield;
			}
		}
		else {
			int r, c;
			cin >> r >> c;
			r--; c--;
			const int target = field[r][c];
			vector<vector<int>>flag(N,vector<int>(N));
			vector<pair<int, int>>que;
			que.push_back(make_pair(c,r));
			flag[r][c] = true;
			while (!que.empty()) {
				auto p = que.back();
				que.pop_back();
				const int ax = p.first;
				const int ay = p.second;
				for (int way = 0; way < 4; ++way) {
					const int nx = ax + adx[way];
					const int ny = ay + ady[way];
					if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
						if (!flag[ny][nx] && field[ny][nx] == target) {
							flag[ny][nx] = true;
							que.push_back(make_pair(nx, ny));
						}
					}
					
				}
			}
			{
				vector<vector<int>>nfield(field);

				for (int dx = 0; dx < N; ++dx) {
					for (int dy = 0; dy < N; ++dy) {
						if (flag[dy][dx]) {

							nfield[dy][dx] = !field[ dy][ dx];
						}
					}
				}
				field = nfield;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			cout << field[i][j];
			if (j == N - 1)cout << endl;
			else cout << " ";
		}
	}
	return 0;
}