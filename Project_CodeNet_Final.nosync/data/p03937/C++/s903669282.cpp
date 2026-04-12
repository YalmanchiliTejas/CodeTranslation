#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int h,w;
	cin >> h >> w;
	char field[h][w];
	rep(i,h){
		rep(j,w){
			cin >> field[i][j];
		}
	}
	bool can = true;
	rep(i,h){
		rep(j,w){
			if(field[i][j]=='.') continue;
			bool a = false;
			bool b = false;
			bool c = false;
			bool d = false;
			if(i==0);
			else if(field[i-1][j] == '#') a = true;
			if(i==h-1);
			else if(field[i+1][j] == '#') c = true;
			if(j==0);
			else if(field[i][j-1] == '#') b = true;
			if(j==w-1);
			else if(field[i][j+1] == '#') d = true;
			//来た未知が2つあったら
			if(a&&b) can = false;
			//行く未知が2つあったら
			if(c&&d) can = false;
		}
	}
	if(can) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}