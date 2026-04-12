#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll dp[3005][3005],a[3005]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int L=n;L>0;--L){
		for(int R=L;R<=n;++R){
			dp[L][R]=max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
		}
	}
	cout<<dp[1][n]<<'\n';
	return 0;
}