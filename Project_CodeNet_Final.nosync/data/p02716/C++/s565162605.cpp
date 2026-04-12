#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
ll dp[maxn][2][2];
ll a[maxn];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dp[1][1][1]=a[1];dp[1][0][1]=-1e18;dp[1][1][0]=-1e18;
	for(int i=2;i<=n;i++){ 
		if(i%2){
			dp[i][0][0]=max(dp[i-1][1][1],dp[i-1][0][1]);dp[i][0][1]=-1e18;dp[i][1][0]=dp[i-1][0][0]+a[i];dp[i][1][1]=dp[i-2][1][1]+a[i];
		}else{
			if(n%2){
				dp[i][1][0]=-1e18;dp[i][1][1]=max(dp[i-2][0][1],dp[i-2][1][1])+a[i];dp[i][0][1]=dp[i-1][1][1];dp[i][0][0]=max(dp[i-1][0][0],dp[i-1][1][0]);
			}else{
				dp[i][0][0]=dp[i][0][1]=dp[i-1][1][1];dp[i][1][0]=dp[i][1][1]=max(dp[i-2][1][0],dp[i-2][0][0])+a[i];
			}
		}
	}printf("%lld\n",max(dp[n][0][0],dp[n][1][0]));
}