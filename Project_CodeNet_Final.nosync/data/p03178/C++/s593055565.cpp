#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 9223372036854775807
#define mini 9223372036854775807
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
pair<ll,ll>s4[4]={{-1,0},{1,0},{0,-1},{0,1}};
pair<ll,ll>s8[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
ll d;
string k;
ll arr[10007];
ll dp[10007][2][105];
ll func(ll i,ll tight,ll sum)
{
	if(dp[i][tight][sum]!=-1)
		return dp[i][tight][sum];
	ll ans=0;
	if(i>=k.size())
	{
		if((sum%d)==0)
			return 1;
		else 
			return 0;
	}
	if(tight==1)
	{
		ll j;
		for(j=0; j<arr[i]; j++)
		{
			ans=((ans%mod)+(func(i+1,0,(sum+j)%d)%mod))%mod;
		}
		ans=((ans%mod)+(func(i+1,1,(sum+arr[i])%d)%mod))%mod;
	}
	else
	{
		ll j;
		for(j=0; j<=9; j++)
		{
			ans=((ans%mod)+(func(i+1,0,(sum+j)%d)%mod))%mod;
		}
	}
	return dp[i][tight][sum]=ans;
}
int main()
{
    boost
    cin>>k>>d;
    ll i,j;
    for(i=0; i<10007; i++)
    {
    	for(j=0; j<105; j++)
    	{
    		dp[i][0][j]=-1;
    		dp[i][1][j]=-1;
    	}
    }
    char zz='0';
    for(i=0; i<k.size(); i++)
    {
    	arr[i]=(ll)(k[i]-zz);
    }
    ll ans=func(0,1,0)%mod;
    ans=(ans-1+mod)%mod;
    cout<<ans<<endl;
    return 0;
}