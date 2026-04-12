#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

vector<string> room;
vector<vector<int> > dir;

bool dfs(int y0, int x0, int y1, int x1){
	if(y0 == y1 && x0 == x1)
		return true;

	for(int i=0; i<4; ++i){
		dir[y0][x0] = i;
		int y = y0 + dy[i];
		int x = x0 + dx[i];
		if(room[y][x] == '#' || (dir[y][x] != -1 && dir[y][x] == (i+2)%4))
			continue;
		if(dfs(y, x, y1, x1))
			return true;
	}

	dir[y0][x0] = -1;
	return false;
}

int main()
{
	int h, w, m;
	cin >> h >> w >> m;

	room.assign(h+2, string(w+2, '#'));
	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			cin >> room[i][j];
		}
	}

	vector<vector<int> > per(h+2, vector<int>(w+2));
	vector<vector<int> > on = per, off = per;
	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			cin >> per[i][j];
		}
	}
	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			cin >> on[i][j];
		}
	}
	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			cin >> off[i][j];
		}
	}
	vector<int> taskY(m), taskX(m);
	for(int i=0; i<m; ++i){
		cin >> taskY[i] >> taskX[i];
		++ taskY[i];
		++ taskX[i];
	}

	int t = 0;
	dir.assign(h+2, vector<int>(w+2, -1));
	vector<vector<int> > prev(h+2, vector<int>(w+2, -1));
	int y = taskY[0];
	int x = taskX[0];
	prev[y][x] = 0;
	int ret = on[y][x];

	for(int i=1; i<m; ++i){
		dfs(y, x, taskY[i], taskX[i]);
		while(y != taskY[i] || x != taskX[i]){
			int d = dir[y][x];
			dir[y][x] = -1;
			y += dy[d];
			x += dx[d];
			++ t;

			if(prev[y][x] == -1){
				ret += on[y][x];
			}else{
				ret += min(off[y][x] + on[y][x], per[y][x] * (t - prev[y][x]));
			}
			prev[y][x] = t;
		}
	}

	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			if(prev[i][j] != -1){
				ret += off[i][j];
			}
		}
	}

	cout << ret << endl;
	return 0;
}