#include<bits/stdc++.h>
#define int long long int
using namespace std;
int n,dp[3001][3001],a[3001];
int rec(int l,int r){
	if(l>r)swap(l,r);
	if(dp[l][r]!=0)return dp[l][r];
	return dp[l][r]=max(a[l]-rec(l+1,r),a[r]-rec(l,r-1));
}
main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dp[i][i]=a[i];
	}
	cout<<rec(1,n);
}