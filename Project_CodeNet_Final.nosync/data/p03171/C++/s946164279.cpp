#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll N;
	cin>>N; 
	ll value[N]; ll dp[N][N];
		
	for(ll i=0;i<N;i++)
	{
	cin>>value[i];
	dp[i][i]=value[i];
	}
	
	for(ll len=2;len<=N;len++)
	{
		for(ll i=0;i<=N-len;i++)
		{
		  dp[i][i+len-1]=max(value[i]-dp[i+1][i+len-1],value[i+len-1]-dp[i][i+len-2]);
		}
	}
	
cout<<dp[0][N-1]<<endl;
	    
	    
	
}

