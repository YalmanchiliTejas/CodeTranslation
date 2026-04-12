#include<iostream>
using namespace std;
const int N=3003;
const int mod=998244353;
int dp[N],A[N];
int ans;
int n,s;
void solve()
{
	int i,j;
	cin>>n>>s;
	for(i=1;i<=n;i++) cin>>A[i];
	for(i=1;i<=n;i++)
	{
		for(j=s;j>=A[i];j--)
		{
			dp[j]=(dp[j-A[i]]+dp[j])%mod;
		}
		if(A[i]<=s) dp[A[i]]=(dp[A[i]]+i)%mod;
		ans=(dp[s]+ans)%mod;
	}
	cout<<ans<<endl;
}
int main()
{
	solve();
	return 0;
}