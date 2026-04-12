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
#define int long long
const int N=3000;
int n;
int a[N+1];
int dp[N+1][N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--)for(int j=i;j<=n;j++)
		dp[i][j]=n+i+j&1?max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]):min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
	cout<<dp[1][n];
	return 0;
}
/*1
4
10 80 90 30
*/
/*2
3
10 100 10
*/
/*3
1
10
*/
/*4
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
*/
/*5
6
4 2 9 7 1 5
*/