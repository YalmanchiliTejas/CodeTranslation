#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int lx[50], ry[50], rx[50], ly[50];
vector<int> vecX;
vector<int> vecY;

bool isExistTate[101][102];	//isExistTate[ymin][x] = 縦線のフラグ.
bool isExistYoko[102][101];	//isExistYoko[y][xmin] = 横線のフラグ.
int label[101][101];		//label[y][x] = (x, y)--(x+1, y+1)を対角線とする正方形領域のラベル番号
int h, w;

void init() {
	int i, j;
	
	vecX.clear();
	vecY.clear();
	for (i = 0; i < 101; i++) for (j = 0; j < 102; j++) isExistTate[i][j] = false;
	for (i = 0; i < 102; i++) for (j = 0; j < 101; j++) isExistYoko[i][j] = false;
	for (i = 0; i < 101; i++) for (j = 0; j < 101; j++) label[i][j] = 0;
}

void solve() {
	int i, j;
	
	for (i = 0; i < n; i++) {
		cin >> lx[i] >> ry[i] >> rx[i] >> ly[i];
		vecX.push_back(lx[i]);
		vecX.push_back(rx[i]);
		vecY.push_back(ly[i]);
		vecY.push_back(ry[i]);
	}
	vecX.push_back(-1);
	vecX.push_back(1145140);
	vecY.push_back(-1);
	vecY.push_back(1145140);
	sort(vecX.begin(), vecX.end());
	vecX.erase(unique(vecX.begin(), vecX.end()), vecX.end());
	sort(vecY.begin(), vecY.end());
	vecY.erase(unique(vecY.begin(), vecY.end()), vecY.end());
	for (i = 0; i < n; i++) {
		lx[i] = lower_bound(vecX.begin(), vecX.end(), lx[i]) - vecX.begin();
		rx[i] = lower_bound(vecX.begin(), vecX.end(), rx[i]) - vecX.begin();
		ly[i] = lower_bound(vecY.begin(), vecY.end(), ly[i]) - vecY.begin();
		ry[i] = lower_bound(vecY.begin(), vecY.end(), ry[i]) - vecY.begin();
	}
	
	h = vecY.size() - 1;
	w = vecX.size() - 1;
	for (i = 0; i < n; i++) {
		for (j = lx[i]; j < rx[i]; j++) {
			isExistYoko[ly[i]][j] = true;
			isExistYoko[ry[i]][j] = true;
		}
		for (j = ly[i]; j < ry[i]; j++) {
			isExistTate[j][lx[i]] = true;
			isExistTate[j][rx[i]] = true;
		}
	}
	
	//labeling
	typedef pair<int, int> P;	//(y, x)
	int labelNum = 0;
	
	for (i = 0; i < h; i++) for (j = 0; j < w; j++) label[i][j] = -1;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (label[i][j] != -1) continue;
			
			queue<P> que;
			que.push(P(i, j));
			label[i][j] = labelNum;
			while (!que.empty()) {
				P now = que.front(); que.pop();
				int y = now.first;
				int x = now.second;
				
				//label[y][x] -> label[y - 1][x]
				if (y > 0 && !isExistYoko[y][x] && label[y - 1][x] == -1) {
					que.push(P(y - 1, x));
					label[y - 1][x] = labelNum;
				}
				
				//label[y][x] -> label[y + 1][x]
				if (y < h - 1 && !isExistYoko[y + 1][x] && label[y + 1][x] == -1) {
					que.push(P(y + 1, x));
					label[y + 1][x] = labelNum;
				}
				
				//label[y][x] -> label[y][x - 1]
				if (x > 0 && !isExistTate[y][x] && label[y][x - 1] == -1) {
					que.push(P(y, x - 1));
					label[y][x - 1] = labelNum;
				}
				
				//label[y][x] -> label[y][x + 1]
				if (x < w - 1 && !isExistTate[y][x + 1] && label[y][x + 1] == -1) {
					que.push(P(y, x + 1));
					label[y][x + 1] = labelNum;
				}
			}
			labelNum++;
		}
	}
	cout << labelNum << endl;
}

int main() {
	while (cin >> n) {
		if (!n) break;
		init();
		solve();
	}
	return 0;
}
