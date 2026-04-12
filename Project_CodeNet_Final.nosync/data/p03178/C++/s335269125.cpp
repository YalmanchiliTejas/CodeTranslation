#include <bits/stdc++.h>
using namespace std;
int d;
int mod = 1000000007;
int arr[10001];
long long dp[10001][101][2];
long long getsum(int ind,int n,int sum, int flag){
	if(ind == n){
		if(sum%d) return 0;
		return 1;
	}
	if(dp[ind][sum][flag]!=-1) return dp[ind][sum][flag]; 
	int limit = 9;
	if(!flag) limit = arr[ind];
	long long ans  = 0;
	for(int i=0;i<=limit;i++){
		if(flag || i<arr[ind]) ans += getsum(ind + 1, n,( sum + i)%d, 1), ans = ans%mod;
		else ans  += getsum(ind + 1, n, ( sum + i)%d, 0), ans = ans%mod ;
	}
	return dp[ind][sum][flag] = ans;
}

int main() {

//	int t;
//	cin>>t;
//	while(t--){
		string a;
		cin>>a;
		cin>>d;
	
		for(int i=0;i<10001;i++) for(int j=0;j<101;j++) for(int k=0;k<2;k++) dp[i][j][k]=-1;
		
		for(int i=0;i<a.size();i++) arr[i] = a[i] - '0';
		long long ans = getsum(0,a.size(),0, 0);
		ans = (ans -1 + mod)%mod;
		cout<<ans<<endl;
//	}

}