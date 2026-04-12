#include<bits/stdc++.h>
using namespace std;
long long int a[3001];
long long int dp[3001];
int main(){
	long long int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	for(j=1;j+i-1<=n;j++)
	dp[j]=max(a[j]-dp[j+1],a[j+i-1]-dp[j]);
	cout<<dp[1];
}