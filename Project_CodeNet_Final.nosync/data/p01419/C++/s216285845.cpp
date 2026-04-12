#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int R, C, M;
string field[50];
bool visited[50][50];

bool dfs(int px, int py, int gx, int gy, vector<int>& res)
{
	
	if(visited[px][py]) return false;
	visited[px][py] = true;


	if(px == gx && py == gy){
		return true;
	}

	for(int i=0; i<4; i++)
	{
		int tx = px + dx[i];
		int ty = py + dy[i];

		if(tx < 0 || ty < 0 || tx >= C || ty >= R) continue;
		if(field[ty][tx] == '#') continue; 

		if(dfs(tx,ty,gx,gy,res)) {
			res.push_back(ty*50+tx);
			return true;
		}

	}

	return false;
	
}

int main()
{
	cin >> R >> C >> M;

	for(int i=0; i<R; i++)
		cin >> field[i];

	int upkeep[50][50], oncost[50][50], offcost[50][50];
	int objx[1000], objy[1000];

	for(int i=0; i<R; i++)
	for(int j=0; j<C; j++)
		cin >> upkeep[j][i];

	for(int i=0; i<R; i++)
	for(int j=0; j<C; j++)
		cin >> oncost[j][i];

	for(int i=0; i<R; i++)
	for(int j=0; j<C; j++)
		cin >> offcost[j][i];

	for(int i=0; i<M; i++)
		cin >> objy[i] >> objx[i];

	int cost=0;
	vector<vector<int> > route(50*50);
	route[objy[0]*50+objx[0]].push_back(cost++);

	for(int i=0; i<M-1; i++) {
		vector<int> r; 

		memset(visited, 0, sizeof(visited));
		dfs(objx[i], objy[i], objx[i+1], objy[i+1], r);

		reverse(r.begin(), r.end());

		for(int j=0; j<r.size(); j++) {
			int a = r[j];

			route[a].push_back(cost++);
		}
	}

	int res = 0;
	for(int i=0; i<2500; i++) {
		int x = (i % 50);
		int y = (i / 50);

		for(int j=0; j<route[i].size(); j++) {
			if(j+1 == route[i].size()) {

				res += offcost[x][y];
				if(route[i].size() == 1) res += oncost[x][y];
			}
			else {
				if(j==0) res += oncost[x][y];

				int diff = route[i][j+1] - route[i][j];	
				res += min(diff*upkeep[x][y], offcost[x][y] + oncost[x][y]);
			}
		}
	}

	cout << res << endl;

}