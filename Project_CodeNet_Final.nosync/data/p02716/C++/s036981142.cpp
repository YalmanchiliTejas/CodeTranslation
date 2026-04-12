#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;
const ll inf = -1e18;
int a[N+100];
ll dp[N+100][2];

int main()
{
	int n;;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=N;i++){
		dp[i][0] = dp[i][1] = inf;
	}
	if((n&1)==0){
		dp[1][0] = a[1];
		dp[2][0] = a[2];
		for(int i=3;i<=n;i++){
			if(i&1){
				dp[i][0] = dp[i-2][0]+a[i];
			}
			else{
				dp[i][0] = max(dp[i][0],dp[i-2][0]+a[i]);
				dp[i][0] = max(dp[i][0],dp[i-3][0]+a[i]);
			}
		}
		printf("%lld\n",max(dp[n][0],dp[n-1][0]));
	}
	else{
		dp[1][0] = 0;
		dp[1][1] = a[1];
		dp[2][1] = a[2];
		dp[3][0] = a[3];
		dp[3][1] = a[3]+a[1];
		for(int i=4;i<=n;i++){
			if(i&1){
				dp[i][0] = max(dp[i][0],dp[i-2][0]+a[i]);
				dp[i][0] = max(dp[i][0],dp[i-3][1]+a[i]);
				dp[i][0] = max(dp[i][0],dp[i-4][1]+a[i]);
				dp[i][1] = dp[i-2][1]+a[i];
			}
			else{
				dp[i][1] = max(dp[i][1],dp[i-2][1]+a[i]);
				dp[i][1] = max(dp[i][1],dp[i-3][1]+a[i]);
			}
		}
		printf("%lld\n",max(dp[n][0],max(dp[n-1][1],dp[n-2][1])));
	}
}
