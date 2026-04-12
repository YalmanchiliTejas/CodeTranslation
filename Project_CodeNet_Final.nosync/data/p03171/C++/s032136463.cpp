//Problem *
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3005;
int n;ll a[N],dp[N][N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)for(int l=1;l<=n-i+1;l++){
		int r=l+i-1;
		dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
	}
	printf("%lld",dp[1][n]);
	return 0;
}