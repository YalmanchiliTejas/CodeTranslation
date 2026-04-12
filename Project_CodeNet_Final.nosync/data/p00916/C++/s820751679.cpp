#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, ax[100], ay[100], bx[100], by[100];
vector<int>X, Y; long long p[150][150]; bool used[150][150];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int main() {
	while (true) {
		X.clear(); Y.clear(); cin >> n; if (n == 0)break;
		for (int i = 0; i < 22500; i++) { p[i / 150][i % 150] = 0; used[i / 150][i % 150] = false; }
		for (int i = 0; i < n; i++) {
			cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
			if (ax[i] > bx[i])swap(ax[i], bx[i]);
			if (ay[i] > by[i])swap(ay[i], by[i]);
			X.push_back(ax[i]); X.push_back(bx[i]);
			Y.push_back(ay[i]); Y.push_back(by[i]);
		}
		sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());
		for (int i = 0; i < n; i++) {
			int pos1 = lower_bound(X.begin(), X.end(), ax[i]) - X.begin(), pos2 = lower_bound(Y.begin(), Y.end(), ay[i]) - Y.begin();
			int pos3 = lower_bound(X.begin(), X.end(), bx[i]) - X.begin(), pos4 = lower_bound(Y.begin(), Y.end(), by[i]) - Y.begin();
			pos1 += 5; pos2 += 5; pos3 += 5; pos4 += 5;
			for (int j = pos1; j < pos3; j++) {
				for (int k = pos2; k < pos4; k++)p[j][k] += (1LL << i);
			}
		}
		int cnts = 0;
		for (int i = 0; i < 150; i++) {
			for (int j = 0; j < 150; j++) {
				if (used[i][j] == true)continue;
				queue<pair<int, int> >Q; cnts++; Q.push(make_pair(i, j)); used[i][j] = true;
				while (!Q.empty()) {
					int a1 = Q.front().first, a2 = Q.front().second; Q.pop();
					for (int k = 0; k < 4; k++) {
						int cx = a1 + dx[k], cy = a2 + dy[k];
						if (cx < 0 || cy < 0 || cx >= 150 || cy >= 150)continue;
						if (used[cx][cy] == true || p[a1][a2] != p[cx][cy])continue;
						Q.push(make_pair(cx, cy)); used[cx][cy] = true;
					}
				}
			}
		}
		cout << cnts << endl;
	}
	return 0;
}