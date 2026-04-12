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
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//-------------------------------Template--Above------------------------------------------------
string digs;
ll d;
ll dp[100001][105][2];
ll solve(ll pos,ll sum,ll tight)
{
	if(pos==digs.size())
	{
		if(sum%d==0) return 1;
		else return 0;
	}
	if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];
	ll ans=0;
	if(tight==1)
	{
		ans=(ans+solve(pos+1,(sum+digs[pos]-'0')%d,1))%M;
		for(ll i=digs[pos]-1-'0';i>=0;i--)
		{
			ans=(ans+solve(pos+1,(sum+i)%d,0))%M;
		}
	}
	else
	{
		for(ll i=9;i>=0;i--)
		{
			ans=(ans+solve(pos+1,(sum+i)%d,0))%M;
		}
	}
	return dp[pos][sum][tight]=ans;
}

int main()
{
	boost
	cin>>digs;
	cin>>d;
	memset(dp,-1,sizeof(dp));
	cout<<(solve(0,0,1)-1+M)%M<<endl;
	return 0;
}
