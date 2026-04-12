/*
  Vivek Rathi
  CSE 2nd Year
  MNNIT
*/
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e17
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll a[3001];
ll n;
pair<ll,ll> dp[3001][3001][2];
pair<ll,ll> solve(ll i,ll j,ll f)
{
	if(i>j) return mp(0,0);
	if(dp[i][j][f].fi!=-1) return dp[i][j][f];
	pair<ll,ll> ans1=solve(i+1,j,(f+1)%2);
	if(f==0) ans1.fi+=a[i];
	else ans1.se+=a[i];
	pair<ll,ll> ans2=solve(i,j-1,(f+1)%2);
	if(f==0) ans2.fi+=a[j];
	else ans2.se+=a[j];
	if(f==0&&ans1.fi-ans1.se<=ans2.fi-ans2.se) return dp[i][j][f]=ans2;
	if(f==0&&ans1.fi-ans1.se>=ans2.fi-ans2.se) return dp[i][j][f]=ans1;
	if(f==1&&ans1.fi-ans1.se<=ans2.fi-ans2.se) return dp[i][j][f]=ans1;
	if(f==1&&ans1.fi-ans1.se>=ans2.fi-ans2.se) return dp[i][j][f]=ans2;
}
int main()
{
	boost
	for(ll i=0;i<3001;i++)
	{
		for(ll j=0;j<3001;j++)
		{
			for(ll k=0;k<2;k++)
			{
				dp[i][j][k]=mp(-1,-1);
			}
		}
	}
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	pair<ll,ll> tmp = solve(0,n-1,0);
	cout<<tmp.fi-tmp.se<<endl;
	return 0;
}