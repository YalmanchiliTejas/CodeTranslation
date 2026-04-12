		#include<bits/stdc++.h>

using namespace std;

long long int dizi[20005],dp[3005][3005],n;

long long int dpf(int sol,int sag){
	if(sol==sag){
		return dizi[sol];
	}
	if(dp[sol][sag]!=-1){
		return dp[sol][sag];
	}
	dp[sol][sag]=max( dizi[sol]+(-dpf(sol+1,sag)), dizi[sag]+(-dpf(sol,sag-1)) );
	return dp[sol][sag];
}
int main(){
	// freopen("a.gir","r",stdin);
	// freopen("a.cik","w",stdout);
	for(int i=0;i<3002;i++){
		for(int j=0;j<3002;j++){
			dp[i][j]=-1;
		}
	}
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&dizi[i]);
	}
	
	printf("%lld\n",dpf(0,(n-1)) );
}