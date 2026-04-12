/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        998244353
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  3009
ll dp[N][N];
ll n,s;
std::vector<ll> a(N);
ll func(ll pos,ll sum)
{
	if(sum==s)
		return (n-pos+1)%hell;
	if(sum>s)
		return 0;
	if(pos>=n)
		return sum==s;
	if(dp[pos][sum]!=-1)
		return dp[pos][sum]%hell;
	return dp[pos][sum]=((func(pos+1,sum))%hell+(func(pos+1,sum+a[pos]))%hell)%hell;


}
int main()
{
	
	io

	rep(i,0,N)
	{
		rep(j,0,N)
		{
			dp[i][j]=-1;
		}
	}
	cin>>n>>s;
	rep(i,0,n)
	cin>>a[i];	
	ll res=0;
	rep(i,0,n)
	{
		res=((res%hell)+(func(i,0))%hell)%hell;
	}
	cout<<res%hell;
	
}