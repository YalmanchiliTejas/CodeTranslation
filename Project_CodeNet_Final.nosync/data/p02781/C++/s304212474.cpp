#include <cstring>
#include <cstdio>
#define INF 1e9
#define eps 1e-6
typedef long long ll;

char c[210];
int k, n, dp[110][20][5][2];

int dfs(int now, int las, int cnt, bool have0){
	//printf("%d %d %d %d\n", now, las, cnt, have0);
	if(now == n + 1)
		return cnt == k;
	if(cnt > k) return 0;
	if(dp[now][las][cnt][have0] >= 0 && !have0)
		return dp[now][las][cnt][have0];
	int maxx = have0 ? c[now] - '0' : 9, sum = 0;
	for(int i = 0; i <= maxx; i++)
		sum += dfs(now + 1, i, cnt + (i != 0), have0 && (i == maxx));
	return dp[now][las][cnt][have0] = sum;
}

int main(){

	memset(dp, -1, sizeof(dp));
	scanf("%s\n%d", c + 1, &k);
	n = strlen(c + 1);
	printf("%d\n", dfs(1, 0, 0, 1));

	return 0;
}
