#include <bits/stdc++.h>
#define MD 1000000007
using namespace std;
char k[10010];
typedef long long ll;
int d;
ll dp[10010][110][2];
void ds(int dg) {
	for(int j=0;j<d;j++) {
		for(int i=0;i<10;i++) {
			dp[dg+1][(j+i)%d][0] += dp[dg][j][0];
			dp[dg+1][(j+i)%d][0] %= MD;
		}
		int dv = k[dg]-'0';
		for(int i=0;i<=dv;i++) {
			dp[dg+1][(j+i)%d][i==dv] += dp[dg][j][1];
			dp[dg+1][(j+i)%d][i==dv] %= MD;
		}
	}
}
int main() {
	scanf("%s ",k);
	scanf("%d ",&d);
	int l = strlen(k);
	memset(dp,0,sizeof(dp));
	dp[0][0][1] = 1;
	for(int i=0;i<l;i++) {
		ds(i);
	}
	int val = -1;
	for(int i=0;i<2;i++) {
		val += dp[l][0][i];
	}
		//printf("%d\n",dp[l][0][1]);
	val += MD;
	printf("%d\n",val%MD);
}
