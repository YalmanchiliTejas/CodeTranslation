#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

char b[8][8];
int v[8][8];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;

	int cnt = 0;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> b[i][j];
			cnt += b[i][j] == '#';
		}
	}

	queue<P> q;
	q.push(P(0, 0));
	while(q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if(x + 1 < W && b[y][x + 1] == '#' && !v[y][x + 1]) {
			v[y][x + 1] = 1;
			q.push(P(x + 1, y));
		}
		if(y + 1 < H && b[y + 1][x] == '#' && !v[y + 1][x]) {
			v[y + 1][x] = 1;
			q.push(P(x, y + 1));
		}
	}

	if(v[H - 1][W - 1] && cnt == H + W - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}