#include<bits/stdc++.h>

#define int long long
// #define max(a,b) max((signed)a,(signed)b);
#define min(a,b) min((signed)a,(signed)b);

using namespace std;

int dp[3005][3005]={0};
//int dp[100005]={0};

signed main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(i==j){
				dp[i][i] = a[i];
			}
			else{
				dp[i][j] = max((a[i]-dp[i+1][j]),(a[j]-dp[i][j-1]));
			}
		}
	}
	for(int i=0;i<n;i++){
		// for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
		// cout<<"\n";
	}
	cout<<dp[0][n-1]<<"\n";
}
