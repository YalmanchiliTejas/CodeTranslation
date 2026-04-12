#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint h, w, m;
char map[55][55];
vector<llint> vec[55][55];
bool used[55][55];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
llint a[55][55], b[55][55], c[55][55];

llint dfs(llint x, llint y, llint gx, llint gy, llint px, llint py, llint t)
{
	if(x == gx && y == gy){
		vec[x][y].push_back(t);
		return 0;
	}
	llint nx, ny;
	for(int i = 0; i < 4; i++){
		nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
		if(map[nx][ny] == '#') continue;
		if(nx == px && ny == py) continue;
		llint res = dfs(nx, ny, gx, gy, x, y, t+1);
		if(res >= 0){
			vec[x][y].push_back(t);
			return res+1;
		}
	}
	return -1;
}

int main(void)
{
	cin >> h >> w >> m;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> map[x][y];
		}
	}
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> a[x][y];
		}
	}
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> b[x][y];
		}
	}for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> c[x][y];
		}
	}
	
	llint x, y, gx, gy, t = 0;
	cin >> y >> x;
	for(int q = 0; q < m; q++){
		cin >> gy >> gx;
		t += dfs(x, y, gx, gy, -1, -1, t);
		x = gx, y = gy;
	}
	
	llint ans = 0;
	for(int x = 0; x < w; x++){
		for(int y = 0; y < h; y++){
			if(vec[x][y].size() == 0) continue;
			for(int i = 1; i < vec[x][y].size(); i++){
				ans += min(b[x][y]+c[x][y], (vec[x][y][i]-vec[x][y][i-1])*a[x][y]);
			}
			ans += b[x][y]+c[x][y];
		}
	}
	cout << ans << endl;
	
	return 0;
}
