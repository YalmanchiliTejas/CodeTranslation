#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[3001][3001];
int pr[3003];
int fun(int l, int r){
	if(l==r)
		return dp[l][r] = pr[r]-pr[l-1];
	if(dp[l][r]!=0)
		return dp[l][r];
	
	return dp[l][r] = max( pr[r] - pr[l-1] - fun(l+1,r) , pr[r] - pr[l-1] - fun(l,r-1));
}
main(){
	int n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>pr[i];
		pr[i]+=pr[i-1];
	}
	
	cout<<2*fun(1,n) - pr[n]<<endl;

}