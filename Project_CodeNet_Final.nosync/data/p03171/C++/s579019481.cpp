#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3005][3005],n,x,sum=0ll;
vector<ll>v;
ll score(int l,int r)
{
    if(r<l)return 0;
    if(l==r)return v[l];
    if(dp[l][r]!=-1)return dp[l][r];
    ll ans1=0,ans2=0;
    ans1=v[l]+min(score(l+2,r),score(l+1,r-1));
    ans2=v[r]+min(score(l+1,r-1),score(l,r-2));
    dp[l][r]=max(ans1,ans2);
    return dp[l][r];
}
int main()
{
	for(int i=0;i<3005;i++)for(int j=0;j<3005;j++)dp[i][j]=-1; 
	cin>>n;	
	for(int i=0;i<n;i++)
	{
        cin>>x;
        v.push_back(x);
        sum+=x;
	}
	cout<<2*score(0,n-1)-sum;
}