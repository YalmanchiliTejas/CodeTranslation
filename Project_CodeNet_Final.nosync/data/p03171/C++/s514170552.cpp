#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
#define pb push_back
#define mp make_pair

ll dp[3004][3004];

int main(){
	int i,n,j;
	scanf("%d",&n);
	ll a[3005],sum[3005];
	sum[0]=0;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}

	for(i=1;i<=n;i++){
		dp[i][i]=a[i];
	}

	for(i=n;i>=1;i--){
		for(j=i+1;j<=n;j++){
			dp[i][j] = max(a[i]+sum[j]-sum[i]-dp[i+1][j],a[j]+sum[j-1]-sum[i-1]-dp[i][j-1]);
		}
	}

	printf("%lld\n",2*dp[1][n]-sum[n] );
	return 0;
}
