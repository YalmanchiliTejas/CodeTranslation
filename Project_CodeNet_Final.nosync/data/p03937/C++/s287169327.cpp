#include<iostream>

using namespace std;

char b[9][9], c[9][9];
int h, w;

void dfs(int y = 0, int x = 0){
	c[y][x] = '#';
	if(x == w - 1 && y == h - 1){
		return ;
	}
	if(x < w - 1 && b[y][x + 1] == '#'){
		dfs(y, x + 1);
	}else if(y < h - 1 && b[y + 1][x] == '#'){
		dfs(y + 1, x);
	}
}

int main(){
	cin >> h >> w;
	for(int i = 0; i <= h; i++){
		for(int j = 0; j <= w; j++){
			c[i][j] = '.';
			if(i == h || j == w){
				b[i][j] = '.';
			}else{
				cin >> b[i][j];
			}
		}
	}
	bool ans = true;
	dfs();
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(b[i][j] != c[i][j]){
				ans = false;
				break;
			}
		}
		if(!ans) break;
	}
	if(ans){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
	return 0;
}