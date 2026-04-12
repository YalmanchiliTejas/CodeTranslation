#include<bits/stdc++.h>
using namespace std;
int n,s,a[3200],dp[3200],result,MOD=998244353;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[0]++;
		for(int j=s;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%MOD;
		result=(result+dp[s])%MOD; 
	}
	cout<<result<<endl;
	return 0;
}
