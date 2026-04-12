#include <bits/stdc++.h>
using namespace std;

char A[10][10];
bool flag = 0;
int H,W;
int bn = 0;
void dfs(int x,int y,int cnt){
	if(x==H-1&&y==W-1&&cnt == bn)flag = 1;
	if(A[x][y+1]=='#')dfs(x,y+1,cnt+1);
	if(A[x+1][y]=='#')dfs(x+1,y,cnt+1);
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> H >> W;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++){
		cin >> A[i][j];
		if(A[i][j]=='#')bn++;
	}
	dfs(0,0,1);
	if(flag)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}