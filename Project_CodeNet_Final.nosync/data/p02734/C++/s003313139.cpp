#include<iostream>
using namespace std;
int N,S,A[3000];
long mod=998244353,dp[3001];
main()
{
	cin>>N>>S;
	dp[0]=1;
	long ans=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		if(S>=A[i])(ans+=dp[S-A[i]]*(N-i))%=mod;
		for(int j=S-A[i]-1;j>=0;j--)
		{
			(dp[j+A[i]]+=dp[j])%=mod;
		}
		dp[0]++;
	}
	cout<<ans<<endl;
}
