#include<bits/stdc++.h>
using namespace std; 

int n ; 
long long int a[3003];
long long int dp[3003][3003];
long long int func(int st , int en,int t)
{
	if(t)
	{
		if(st==en)
		return(a[st]);
		
		if(dp[st][en]!=-1)
		return(dp[st][en]); 
		
		return(dp[st][en]= max(func(st+1,en,0)+a[st],func(st,en-1,0)+a[en]));
	}
	else
	{
		if(st==en)
		return(-a[st]);
		
		if(dp[st][en]!=-1)
		return(dp[st][en]); 
		
		return(dp[st][en]= min(func(st+1,en,1)-a[st],func(st,en-1,1)-a[en]));
	}
	
}

int main()
{  ios_base::sync_with_stdio(false);cin.tie(NULL);
cin>>n ; 
for(int i = 0; i<n ; i++)
cin>>a[i];
memset(dp,-1,sizeof(dp));
cout<<func(0,n-1,1);
return(0);
}
