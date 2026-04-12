#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int dx[] = {0,1,0,-1,0};
const int dy[] = {0,0,1,0,-1};

int tile[10][10];
int tmp[10][10];
int correct(int x,int y){
	return x < 10 && x >= 0 && y < 10 && y >= 0;
}
int getColor(int x,int y){
	int ret = tile[y][x];
	rep(i,5){
		int sx = x + dx[i] , sy = y + dy[i];
		if(!correct(sx,sy))continue;
		if(tmp[sy][sx])ret++;
	}
	return ret%2;
}

int solve(int upperMost){
	rep(i,10)rep(j,10)tmp[i][j] = 0;
	rep(i,10)tmp[0][10-i-1] = (upperMost>>i) & 1;
	//rep(i,10)cout << tmp[0][i] << endl;
	
	for(int i = 1 ; i < 10 ; i++){
		rep(j,10){
			if(getColor(j,i-1) == 1){
				tmp[i][j] = 1;
			}
		}
	}
	
	rep(i,10)rep(j,10)
		if(getColor(j,i))return 0;
	return 1;
}
int main(){
	int N; cin >> N;
	while(N--){
		rep(i,10)rep(j,10)cin >> tile[i][j];
		rep(bit,1<<10){
			if( solve(bit) ){
				rep(i,10){
					rep(j,10)cout << (j?" ":"") << tmp[i][j];
					cout << endl;
				}
				break;
			}
		}
	}
}