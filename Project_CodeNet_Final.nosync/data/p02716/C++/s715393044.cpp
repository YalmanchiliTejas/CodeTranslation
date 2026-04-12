#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

const int D=20;
ll dp[300000][D][2];
ll a[300000];

int main(){
	int n;cin>>n;
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n+1)rep(j,D)rep(k,2){
		dp[i][j][k]=-INFL;
	}
	dp[0][D/2][0]=0;
	rep(i,n)rep(j,D)rep(k,2){
		if(dp[i][j][k]==-INFL)continue;
		if(k==0&&j+1<20){
			dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j][k]+a[i]);
		}
		if(j-1>=0)dp[i+1][j-1][0]=max({dp[i+1][j-1][0],dp[i][j][k]});
	}
	if(n%2==0){
		cout<<max(dp[n][D/2][0],dp[n][D/2][1])<<endl;
	}
	else cout<<max(dp[n][D/2-1][0],dp[n][D/2-1][1])<<endl;
}