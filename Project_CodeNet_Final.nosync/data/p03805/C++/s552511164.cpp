#include <bits/stdc++.h>

using namespace std;

int n,m,i,j;
long long dp[300][10];
bool edge[10][10];

int main(){
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < m; i++){
		int x,y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		edge[x][y] = 1;
		edge[y][x] = 1;
	}
	
	dp[1][0] = 1LL;
	
	for(i = 0; i < (1 << n); i++){
		for(j = 0; j < n; j++){
			if((i & (1 << j)) == 0) continue;
			for(int ii = 0; ii < n; ii++){
				if(i & (1 << ii) || !edge[j][ii]) continue;
				int newmask = i | (1 << ii);
				dp[newmask][ii] += dp[i][j];
			}
		}
	}
	
	long long res = 0;
	
	for(i = 0; i < n; i++)
	res += dp[(1 << n) - 1][i];
	
	printf("%lld\n", res);
}
