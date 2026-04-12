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
const int mod=1000000007;
const int N=10000,M=100;
int n,m;
char a[N+1];
int dp[N+1][M];
int main(){
	cin>>a+1>>m;
	n=strlen(a+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)
		for(int k=0;k<=9;k++)
			(dp[i][j]+=dp[i-1][(j-k+10000*m)%m])%=mod;
	int ans=dp[n-1][0]-1;
	int now=0;
	for(int i=1;i<=n;i++){
		if(i>1)(now+=a[i-1]^48)%=m;
		for(int j=i==1;j<=(a[i]^48)-(i<n);j++)(ans+=dp[n-i][(-now-j+10000*m)%m])%=mod;
	}
	cout<<ans;
	return 0;
}
/*1
30
4
*/
/*2
1000000009
1
*/
/*3
98765432109876543210
58
*/