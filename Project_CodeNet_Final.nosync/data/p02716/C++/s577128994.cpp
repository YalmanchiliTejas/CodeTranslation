#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	long long sum;
	cin>>N;
	vector<long long>a(N);
	for(int i=0;i<N;i++) cin>>a[i];
	vector<long long>dp(N+1);
	sum=a[0];
	for(int i=2;i<=N;i++)
		if(i%2==0) dp[i]=max(a[i-1]+dp[i-2],sum);
		else {
			dp[i]=max(a[i-1]+dp[i-2],dp[i-1]);
			sum+=a[i-1];
		}
	cout<<dp[N]<<"\n";
	return 0;
}