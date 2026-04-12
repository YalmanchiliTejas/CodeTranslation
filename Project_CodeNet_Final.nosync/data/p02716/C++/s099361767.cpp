#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std ;
const long long mod = 998244353 ;
int n,a[200007] ;
map<int,long long>dp[200007] ;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
        cin>>a[i];
	for(int i=1;i<=n;++i)
        dp[i][1]=a[i];
    for(int i=3;i<=n;++i){
		for(int j=max(2,i/2-3);j<=min(n,i/2+3);++j){
		   long long max1=-1e18;
		   for(int k=max(1,i-5);k<=i-2;++k){
                if(dp[k].count(j-1)==0)
                    continue;
                max1=max(max1,dp[k][j-1]+a[i]);
		   }
		   if(max1<-1e17)
                continue;
		   dp[i][j]=max1;
		}
	}
	long long ans = -1e18 ;
	for(int i=max(1,n-10);i<=n;++i)
        if(dp[i].count(n/2))
            ans=max(ans,dp[i][n/2]);
	cout<<ans;
	return 0 ;
}
