#include<bits/stdc++.h>
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mod 1000000007 
#define eps 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define Fr(i,a,b) for(int i=a;i<b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pii>
using namespace std;
ll dp[3005][3005];
ll f(ll i,ll j,ll a[],ll n)
{
	if(i>j)
	return 0;
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	dp[i][j]=max(a[i]+min(f(i+2,j,a,n),f(i+1,j-1,a,n)),a[j]+min(f(i,j-2,a,n),f(i+1,j-1,a,n)));
	return dp[i][j];
}
int main()
{
	SPEED;
   ll n,k,i,s,j;
   cin>>n;
   ll a[n];
   s=0;
   Fr(i,0,n)
   {
   	cin>>a[i];
   	s+=a[i];
   }
   memset(dp,-1,sizeof(dp));
   ll p=f(0,n-1,a,n);
   cout<<2*p-s<<endl;
return 0;   
}

   