
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int board[12][12];
int used[12][12];

bool lastCheck(){
	for(int y=0;y<10;y++){
		for(int x=0;x<10;x++){
			if(board[y][x])return false;
		}
	}
	return true;
}

bool allow(int n){
	for(int i=0;i<n;i++){
		int y = i / 10;
		int x = i % 10;

		if(board[y][x] == 0)continue;

		bool ok = false;
		for(int j=n;j<100;j++){
			int ny = j / 10;
			int nx = j % 10;

			int dy = abs(ny - y);
			int dx = abs(nx - x);

			if(dy >= 2)break;
			if(dy + dx <= 1){
				ok = true;
				break;
			}
		}

		if(!ok)return false;
	}
	return true;
}

int pattern[] = {
    0,1,0,
    1,1,1,
    0,1,0
};

void flip(int y, int x){
	int sy = y - 1;
	int sx = x - 1;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++){
		int ny = sy + i;
		int nx = sx + j;
		if(ny < 0 || ny >= 10 || nx < 0 || nx >= 10)continue;

		if(pattern[i*3+j]){
			board[ny][nx] ^= 1;
		}
	}
}

bool dfs(int n){
	if(n >= 10 * 10){
		return lastCheck();
	}
	if(!allow(n)){
		return false;
	}
	int y = n / 10;
	int x = n % 10;

	if(dfs(n + 1)){
		return true;
	}

	flip(y, x);
	used[y][x] = 1;

	if(dfs(n + 1))return true;
	
	used[y][x] = 0;
	flip(y, x);

	return false;
}

void solve(){
	memset(used, 0, sizeof(used));
	if(!dfs(0)){
		while(1);
	}
}
int main()
{
	int n;
	cin >> n;

	for(int t=0;t<n;t++){
		for(int y=0;y<10;y++){
			for(int x=0;x<10;x++)cin >> board[y][x];
		}
		solve();
		for(int y=0;y<10;y++){
			for(int x=0;x<10;x++){
				if(x > 0)cout << " ";
				cout << used[y][x];
			}
			cout << endl;
		}
	}
	return 0;
}