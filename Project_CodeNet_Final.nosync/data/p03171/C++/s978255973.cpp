#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
int a[3005];
ll dp[3005][3005];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(dp[i]==dp[j])
			dp[i][j]=a[i];
			else
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
			}
		
		}
	cout<<dp[0][n-1]<<endl;
	
	return 0;
	}
