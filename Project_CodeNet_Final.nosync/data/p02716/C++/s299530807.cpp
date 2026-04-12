#include<bits/stdc++.h>
#define st first
#define nd second

using ll = long long;
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
ll dp[N][2];
int a[N];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <=n; i++){
		scanf("%d", &a[i]);
	}
	dp[1][0] = 0LL;
	dp[1][1] = 1LL * a[1];
	dp[2][0] = 1LL * max(a[1], a[2]);
	for(int i = 3; i <= n; i++){
		if(i % 2 == 0){
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][0] + 1LL * a[i]);
		}
		else{
			dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + 1LL * a[i]);
			dp[i][1] = dp[i - 2][1] + 1LL * a[i];
		}
	}
	printf("%lld", dp[n][0]);
}