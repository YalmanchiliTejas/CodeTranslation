#include<bits/stdc++.h>

using namespace std;
int NAX=3001;
#define ll long long

int main(){
	ll n;
	scanf("%lld",&n);
	vector<ll> arr(n);
	for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
	vector<vector<ll> > dp(NAX,vector<ll>(NAX));
	
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(i==j)
				dp[i][j]=arr[i];
			else
				dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
		}
	}
	printf("%lld",dp[0][n-1]);
	
}
