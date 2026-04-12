#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pi;

long long h, w, nx, ny, g[9][9], v[9][9], dx[]={1, 0}, dy[]={0, 1};
char c;
queue<pi> q;
int main(){
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> c;
			if(c == '#') g[i][j] = 0;
			else g[i][j] = 1;
		}
	}
	q.push(pi(0, 0));
	while(!q.empty()){
		pi f = q.front(); q.pop();
		v[f.first][f.second] = 1;
		for(int i = 0; i < 2; i++){
			nx = f.first+dx[i];
			ny = f.second+dy[i];
			if(nx < 0 || ny < 0 || nx >= h || ny >= w || g[nx][ny] == 1 || v[nx][ny] == 1) continue;
			q.push(pi(nx, ny));
			break;
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(g[i][j] == 0 && v[i][j] == 0){
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
}