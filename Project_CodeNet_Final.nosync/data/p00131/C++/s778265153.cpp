
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int board[12][12];
int used[12];
int mask[12];
int all = (1 << 10) - 1;

int makeCurrMask(int curr, int m){
	for(int i=0;i<10;i++){
		if((m >> i) & 1){
			int t = (i == 0) ? (7 >> 1) : (7 << (i - 1));
			curr ^= t;
		}
	}
	return curr & all;
}

bool dfs(int prev, int curr, int index){
	if(index >= 10){
		if(prev)return false;
		return true;
	}
	for(int m=0;m<(1<<10);m++){
		if(index > 0 && prev ^ m)continue;
		int ncurr = makeCurrMask(curr, m);
		int next = mask[index+1] ^ m;

		used[index] = m;
		if(dfs(ncurr, next, index + 1)){
			return true;
		}
	}
	return false;
}

void solve(){
	memset(mask, 0, sizeof(mask));
	memset(used, 0, sizeof(used));
	for(int y=0;y<10;y++){
		int m = 0;
		for(int x=0;x<10;x++){
			m = ((m << 1) + board[y][x]);
		}
		mask[y] = m;
	}
	dfs(-1, mask[0], 0);
}

void output(){
	for(int y=0;y<10;y++){
		int m = used[y];
		for(int x=9;x>=0;x--){
			if(x != 9)cout << " ";
			cout << (((m >> x) & 1) ? 1 : 0);
		}
		cout << endl;
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
		output();
	}
	return 0;
}