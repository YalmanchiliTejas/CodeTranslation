#include <bits/stdc++.h>

using namespace std;

int h,w;
int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {1,0,-1,1,-1,1,0,-1};

bool dfs(int y, int x, vector<vector<bool> > &trot){
	if(!trot[y][x]) return false;
	trot[y][x] = false;
	if(x == w && y == h ) return true;
	if(trot[y-1][x] || trot[y][x-1]) return false;
	if(!trot[y][x+1] && trot[y+1][x])return dfs(y+1,x,trot);
	if(trot[y][x+1] && !trot[y+1][x])return dfs(y,x+1,trot);
	return false;
}

int main(){
	cin >> h >> w;
	vector<vector<bool> > trot(h+2, vector<bool>(w+2,false));
	for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j){
			char c; cin >> c;
			if(c == '#')trot[i][j] = true;
		}
			
	//for(int i = 0; i < trot.size(); ++i){\
		for(int j = 0; j < trot[i].size(); ++j){\
			if(trot[i][j])cout << '#';\
			else cout << '.';}\
		cout << endl;}
	bool flag = dfs(1,1,trot);
	for(int i = 1; i <=h; ++i){
		for(int j = 1; j <=w; ++j){
			if(trot[i][j]){
				flag = false;
	//			cout << "#";
				break;
			}
	//		else cout << ".";
		}
	//	cout << endl;
		if(!flag)break;
	}
	if(flag)cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}

