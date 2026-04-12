#include<bits/stdc++.h>
using namespace std;
int n,dp[1<<17];
int main(){
	cin>>n;
  vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	reverse(a.begin(),a.end());
  fill(dp,dp+n,1<<30);
	for(int i=0;i<n;i++){
    *upper_bound(dp,dp+n,a[i])=a[i];
	}
	cout<<lower_bound(dp,dp+n,1<<30)-dp<<endl;
 }
