#include <bits/stdc++.h>
using namespace std;

int H,W;
bool flag = 0;
int bn = 0;
char s[10][10];

void dfs(int x,int y,int cost){
	if(x==H-1&&y==W-1&&cost==bn)flag = 1;
	if(s[x][y+1]=='#')dfs(x,y+1,cost+1);
	if(s[x+1][y]=='#')dfs(x+1,y,cost+1);
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> H >> W;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++){
		cin >> s[i][j];
		if(s[i][j]=='#')bn++;
	}
	dfs(0,0,1);
	if(flag)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}