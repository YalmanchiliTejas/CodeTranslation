#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

   
int n;ll dp[3][3005][3005];ll a[3005];

ll f(int st,int l,int r)
{  //cout<<"visit "<<st<<" "<<l<<" "<<r<<endl;
	if(dp[st][l][r]!=-1)
	{
//	cout<<"already "<<st<<" "<<l<<" "<<r<<" "<<dp[st][l][r]<<endl;
	return dp[st][l][r];
}
	
	if(l==r)
	{     if(st==0)
		dp[st][l][r]=a[l];
		else
		dp[st][l][r]=-a[l];
	//	 cout<<"base "<<st<<" "<<l<<" "<<r<<" "<<dp[st][l][r]<<endl;
		return a[l];
	}
	f((st+1)%2,l+1,r);
	f((st+1)%2,l,r-1);
	
	if(st==0)
	dp[st][l][r]= max(a[l]+dp[(st+1)%2][l+1][r],a[r]+dp[(st+1)%2][l][r-1]);
	if(st==1)
	dp[st][l][r]= min(dp[(st+1)%2][l+1][r]-a[l],dp[(st+1)%2][l][r-1]-a[r]);
/*	if(st==1 and l==2 and r==4)
	cout<<a[l]<<" "<<dp[(st+1)%2][l+1][r]<<" "<<a[r]<<" "<<dp[(st+1)%2][l][r-1]<<" "<<a[l]-dp[(st+1)%2][l+1][r]<<" "<<a[r]-dp[st+1][l][r-1]<<
	endl;*/
	
//	cout<<"first time "<<st<<" "<<l<<" "<<r<<" "<<dp[st][l][r]<<endl;
	
	
	return dp[st][l][r];
}



main()
{ fastread
	cin>>n;
	
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	for(int i=0;i<3;i++)
	for(int j=0;j<3003;j++)
    for(int k=0;k<3003;k++)
	dp[i][j][k]=-1;
		
	f(0,1,n);
	cout<<dp[0][1][n];
	
}