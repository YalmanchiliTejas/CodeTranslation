#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w; cin >> h >> w;
	vector<string> grid;
	for(int i = 0; i < h; i++){
		string s; cin >> s;
		bool white = true;
		for(int j = 0; j < w; j++){
			if(s[j] == '#') white = false;
		}
		if(!white) grid.push_back(s);
	}
	for(int i = 0; i < w; i++){
		bool white = true;
		for(int j = 0; j < grid.size(); j++){
			if(grid[j][i] == '#') white = false;
		}
		if(white){
			for(int j = 0; j < grid.size(); j++) grid[j][i] = '0';
		}
	}
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < w; j++){
			if(grid[i][j] != '0') cout << grid[i][j];
		}
		cout << endl;
	}
	return 0;	
}





  