#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=3000,M=3000;
int n,m;
int a[N+1];
int dp[M+1];//dp' 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(m==a[i])(ans+=1ll*i*(n-i+1)%mod)%=mod;
		else if(m>a[i])(ans+=1ll*dp[m-a[i]]*(n-i+1)%mod)%=mod;//更新答案 
		for(int j=m;j>=a[i];j--)(dp[j]+=dp[j-a[i]]+(j==a[i]?i:0))%=mod;//转移 
	}
	cout<<ans;
	return 0;
}