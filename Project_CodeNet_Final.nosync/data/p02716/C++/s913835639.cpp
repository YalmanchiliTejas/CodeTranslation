#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,a[N];
const LL inf=1e18;
map<int,LL>dp[N];
int main() {
  	ios::sync_with_stdio(false);
  	cin>>n;LL s=0;
  	//
  	for(int i=1;i<=n;i++)cin>>a[i];
  	for(int i=0;i<=n;i++){
  		for(int j=i/2-1;j<=i/2+1;j++){
  			dp[i][j]=-inf;
  		}
  		dp[i][0]=0;
  	}
  	for(int i=1;i<=n;i++){
  		if(i&1 && i<=i/2+1)dp[i][i]=a[i];
  		for(int j=i-2;j>=0&&i-j<=3;j--){
  			for(int k=j/2-1;k<=j/2+1;k++){
  				if(k>=i/2-2 && k<=i/2){
  					dp[i][k+1]=max(dp[i][k+1],dp[j][k]+a[i]);
  				}
  			}
  		}
  		//if(i%2==0)cout<<i<<' '<<dp[i][i/2+1]<<endl;
  	}
  	LL ans=-inf;
  	for(int i=1;i<=n;i++){
  		if(dp[i].count(n/2)){
  			ans=max(ans,dp[i][n/2]);
  			//cout<<i<<' '<<dp[i][n/2]<<endl;
  		}
  	}
  	cout<<ans<<'\n';
 	return 0;
}