#include<bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define ll long long int

ll dp[3015][3015];
ll a[3015];

int main(){
	AC
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dp[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int j=0;j+k<=n;j++){
			int r=j+k;
			if(k%2==n%2)dp[j][r]=max(dp[j+1][r]+a[j],dp[j][r-1]+a[r-1]);
			else dp[j][r]=min(dp[j+1][r]-a[j],dp[j][r-1]-a[r-1]);
		}
	}
	cout<<dp[0][n]<<endl;
}
