#include<bits/stdc++.h>
using namespace std;
int n,dp[1<<17],a[1<<17],i;
int main(){
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	reverse(a,a+n);
	fill(dp,dp+n,1<<30);
	for(i=0;i<n;i++)*upper_bound(dp,dp+n,a[i])=a[i];
	cout<<lower_bound(dp,dp+n,1<<30)-dp<<endl;
 }
