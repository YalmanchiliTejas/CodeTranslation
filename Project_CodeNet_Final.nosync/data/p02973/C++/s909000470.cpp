#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,dp[100000];
	cin>>n;
	fill(dp,dp+n,1);
	for(int i=0;i<n;i++){
		cin>>a;
		*upper_bound(dp,dp+n,-a)=-a;
	}
	cout<<lower_bound(dp,dp+n,1)-dp<<endl;
}
