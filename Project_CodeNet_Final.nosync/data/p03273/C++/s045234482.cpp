#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

bool check(int row, int column, int inc1, int inc2, int rowtotal, int columntotal, int grid[100][100]){
	for(int i = row, j = column; i < rowtotal && j < columntotal; i += inc1, j += inc2){
		if(grid[i][j] == '#')
			return 0;
	}
	return 1;
}

int main(){
	int h, w;
	cin >> h >> w;
	bool deleted[h+w] = {};
	int grid[100][100] = {};
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			scanf(" %c", &grid[i][j]);
		}
	}
	for(int i = 0; i < h; i++){
		if(check(i, 0, 0, 1, h, w, grid))
			deleted[i] = true;
	}
	for(int i = 0; i < w; i++){
		if(check(0, i, 1, 0, h, w, grid))
			deleted[h+i] = true;
	}
	for(int i = 0; i < h; i++){
		if(deleted[i])
			continue;
		for(int j = 0; j < w; j++){
			if(deleted[h+j])
				continue;
			cout << (char)grid[i][j];
		}
		cout << endl;
	}
}