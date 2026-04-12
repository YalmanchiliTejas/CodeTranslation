/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=3000,M=3000;
int n,m;
int a[N+1];
int dp[M+1];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(m==a[i])(ans+=1ll*i*(n-i+1)%mod)%=mod;
		else if(m>a[i])(ans+=1ll*dp[m-a[i]]*(n-i+1)%mod)%=mod;
		for(int j=m;j>=a[i];j--)(dp[j]+=dp[j-a[i]]+(j==a[i]?i:0))%=mod;
	}
	cout<<ans;
	return 0;
}