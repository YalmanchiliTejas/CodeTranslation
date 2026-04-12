#include <bits/stdc++.h>
using namespace std;
int main() 
{
	long long int n;
	cin>>n;
	vector<long long int> A(n);
	for(long long int i=0;i<n;i++)
	{
	    cin>>A[i];
	}
	vector<vector<pair<long long int,long long int>>> dp(n,vector<pair<long long int,long long int>>(n,make_pair(0,0)));
	for(long long int size=0;size<n;size++)
	{
	    for(long long int i=0;i<n-size;i++)
	    {
	        long long int j=i+size;
	        if(size==0)
	        {
	            dp[i][j].first=A[i];
	            dp[i][j].second=0;
	            continue;
	        }
	        long long int temp1=A[j]+dp[i][j-1].second;
	        long long int temp2=A[i]+dp[i+1][j].second;
	        if(temp1>temp2)
	        {
	            dp[i][j].first=temp1;
	            dp[i][j].second=dp[i][j-1].first;
	        }
	        else
	        {
	            dp[i][j].first=temp2;
	            dp[i][j].second=dp[i+1][j].first;
	        }
	    }
	}
    cout<<dp[0][n-1].first-dp[0][n-1].second;
}