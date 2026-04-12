#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

int loot[10];
int can[10][10];
int counter;

int n;

int memo[10][10];

int dp(int now, int old){
	int ans = 0;
	loot[now] = 1;
	if (counter == 0){
		loot[now] = 0;
		return memo[now][old] = 1; }
	for (int a = 0; a <= n; a++){
		if (can[now][a] != 0 && loot[a] == 0){
			counter--;
			ans += dp(a, now);
			counter++;
		}
	}
	loot[now] = 0;
	return memo[now][old] = ans;
}

int main(){
	memset(memo, 255, sizeof(memo));
	int m;
	int buf, buffer;

	scanf("%d%d", &n, &m);
	counter = n - 1;
	for (int a = 0; a < m; ++a){
		scanf("%d%d", &buf, &buffer);
		can[buf][buffer]++;
		can[buffer][buf]++;
	}

	printf("%d\n", dp(1, 1));

	return 0;
}