/*Template by hemnath_d(Enlightened by chamow)*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec vector<ll>
#define pll pair<ll,ll>
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fx first
#define sx second
#define inf 100000000000000
#define minf -100000000000000
#define maxi 100005
ll n,arr[3000];
ll dp1[3000][3000],dp2[3000][3000];
ll solve2(int,int);
ll solve1(int left,int right)
{
	if(left==right)
		return arr[left];
	else if(dp1[left][right]!=-1)
		return dp1[left][right];
	else
	{
		ll ans;
		ans=max(arr[left]+solve2(left+1,right),arr[right]+solve2(left,right-1));
		dp1[left][right]=ans;
		return ans;
	}
}
ll solve2(int left,int right)
{                              
	if(left==right)
		return -arr[left];
	else if(dp2[left][right]!=-1)
		return dp2[left][right];
	else
	{
		ll ans;
		ans=min(-arr[left]+solve1(left+1,right),-arr[right]+solve1(left,right-1));
		dp2[left][right]=ans;
		return ans;
	}
}
int main()
{
    fastread;
    cin>>n;
    for(int i=0;i<3000;i++)
    	for(int j=0;j<3000;j++)
    	{
    		dp1[i][j]=dp2[i][j]=-1;
    	}
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    cout<<solve1(0,n-1)<<endl;
    return 0;
}