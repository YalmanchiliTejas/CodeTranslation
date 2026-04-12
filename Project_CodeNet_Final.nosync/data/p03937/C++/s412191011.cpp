#include <iostream>
using namespace std;

int W,H;
int field[10][10] = {0};
int num = 0;
bool dfs(int x, int y, int d){
	if(d == 0 && x == W && y == H) return true;
	bool ans = false;
	if(field[y+1][x] == 1){
		if(dfs(x, y+1, d-1))
			ans = true;
	}
	if(field[y][x+1] == 1){
		if(dfs(x+1, y, d-1))
			ans = true;
	}
	field[y][x] = 0;
	return ans;
}

int main()
{
	cin >> H >> W;
	for(int i=1;i<=H;i++){
		string str;
		cin >> str;
		for(int j=1;j<=W;j++){
			if(str[j-1] == '#'){
				field[i][j] = 1;
				num++;
			}
		}
	}
	if(dfs(1,1,num-1))
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}