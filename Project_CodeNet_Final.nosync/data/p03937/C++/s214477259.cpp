#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int main(){
	int h,w,cnt = 0;
	bool used[8][8] = {};
	string field[8];
	cin >> h >> w;
	for(int i = 0;i < h;i++) {
		cin >> field[i];
		for(int j = 0;j < w;j++){
			if(field[i][j] == '#') cnt++;
		}
	}
	if(field[0][0] != '#' || cnt != h + w - 1){
		cout << "Impossible" << endl;
		return 0;
	}
	queue<P> que;
	que.push(P(0,0));
	while(!que.empty()){
		P p = que.front();que.pop();
		int x = p.first,y = p.second;
		if(used[x][y]) continue;
		used[x][y] = true;
		if(x != h - 1){
			if(field[x + 1][y] == '#' && !used[x + 1][y]) {
				que.push(P(x + 1,y));
			}
		}
		if(y != w - 1){
			if(field[x][y + 1] == '#' && !used[x][y + 1]) {
				que.push(P(x,y + 1));
			}
		}
	}
	if(used[h - 1][w - 1]) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}