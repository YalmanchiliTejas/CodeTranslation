#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int n;
int a[4000];
ll dp[4000][4000][2];

ll rec(int i,int j,int k){
	if(dp[i][j][k]!=-1)return dp[i][j][k];
	if(i+j==n)return 0;
	int s=i,t=n-j-1;
	if(k==0){
		return dp[i][j][k]=max(rec(i+1,j,!k)+a[s],rec(i,j+1,!k)+a[t]);
	}
	else{
		return dp[i][j][k]=min(rec(i+1,j,!k),rec(i,j+1,!k));
	}
}
int main(){
	scanf("%d",&n);
	ll sum=0;
	rep(i,n){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	memset(dp,-1,sizeof(dp));
	ll ans=rec(0,0,0);
	ll d=sum-ans;
	cout<<ans-d<<endl;
}