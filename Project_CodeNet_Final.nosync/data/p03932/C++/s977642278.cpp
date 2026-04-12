// failed to generate code

#include <bits/stdc++.h>
using namespace std;

int a[210][210];
int H,W;
int dp[210][210][210];

int dfs(int x,int y,int x2){
	//cout << x << " " << y << " " << x2 << endl;
	if( x >= W ) return 0;
	if( y >= H ) return 0;
	int y2 = (x + y) -x2;
	if( y2 >= H ) return 0;
	if( x2 >= W ) return 0;
	if( y2 < 0 ) return 0;
	if( dp[x][y][x2] != -1 ) return dp[x][y][x2];
	//cout << x2 << " " << y2 << endl;
	int ans = a[y][x];
	if( x != x2 or y != y2 )
		ans += a[y2][x2];
	int ans2 = 0;
	ans2 = max(dfs(x+1,y,x2+1),dfs(x,y+1,x2+1));
	ans2 = max(ans2,max(dfs(x+1,y,x2),dfs(x,y+1,x2)));
	
	return dp[x][y][x2] = ans + ans2;
}

int main(){	
	memset(dp,-1,sizeof(dp));
	ios::sync_with_stdio(false);
	
	cin >> H >> W;
	for(int i = 0 ; i < H ; i++)
		for(int j = 0 ; j < W ; j++)
			cin >> a[i][j];
	cout << dfs(0,0,0) << endl;
}

