#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <math.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
#define int ll
#define INF (1LL<<60)
#define mod 1000000007
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

ll H, W;
ll sy, sx, gy, gx;
char a[52][52];
int d[52][52];

void bfs(){
	queue<P> que;

	for (int h = 1; h <= H; h++)
		for (int w = 1; w <= W; w++) d[h][w] = INF;

	que.push(P(sy, sx));
	d[sy][sx] = 0;

	while (que.size()>0){
		P p = que.front();
		que.pop();

		if (p.first == gy && p.second == gx) break;

		for (int i = 0; i < 4; i++){
			int ny = p.first + dy[i], nx = p.second + dx[i];
			if (1 <= ny && ny <= H && 1 <= nx && nx <= W &&
				a[ny][nx] == '#' && d[ny][nx] == INF){
				que.push(P(ny, nx));
				d[ny][nx] = d[p.first][p.second] + 1;
			}
		}
	}
}

signed main(){

	cin >> H >> W;

	sx = sy = 1;
	gx = W; gy = H;

	int count = 0;
	for (int h = 1; h <= H; h++)
		for (int w = 1; w <= W; w++){
			cin >> a[h][w];
			if (a[h][w] == '#') count++;
		}

	bfs();

	if (d[gy][gx] == H + W - 2 && count == H+W-1)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;

	return 0;
}
