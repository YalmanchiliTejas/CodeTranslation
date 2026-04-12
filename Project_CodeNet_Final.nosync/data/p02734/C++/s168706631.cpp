#include<bits/stdc++.h>
using namespace std;
void solve()
{
	long long n,s;
	cin>>n>>s;
	vector<long long>vec;
	for(int i=0;i<n;i++)
	{
	    long long x;
	    cin>>x;
	    vec.push_back(x);
	}
	long long int dp[n+1][3001];
	long long ans=0;
	for(int i=n-1;i>=0;i--)
	dp[i][0]=n-i+1;
	long long md=998244353;
	dp[n-1][vec[n-1]]=1;
	for(int i=n-2;i>=0;i--)
	{
		for(int j=1;j<=3000;j++)
		{
			dp[i][j]=dp[i+1][j]+(j>=vec[i]?dp[i+1][j-vec[i]]:0);
            dp[i][j]%=md;
		}
	}
	for(int i=0;i<n;i++)
	{
	    ans+=dp[i][s];
	    ans%=md;
	}
	cout<<ans<<endl;
}
int main()
{
    int t=1;
    while(t--){
	solve();
    }
    return 0;
}   