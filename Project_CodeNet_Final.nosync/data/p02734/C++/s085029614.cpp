#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define iiordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define MOD 998244353
ll power(ll a,ll b, ll m=MOD)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll inverse(ll a,ll m=MOD)
{
    return power(a,m-2,m);
}
int ceil(int a,int b)
{
    return (a+b-1)/b;
}
#define INFl (1e18+5)
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define vll vector<pll>
#define vii vector<ii>
#define vvii vector<vii>
#define tri pair<int,ii>
#define F first
#define S second
#define forl(i,n) for(int i=0;i<n;i++)
#define fore(i,n) for(int i=1;i<=n;i++)
#define rforl(i,n)  for(int i=n-1;i>=0;i--)
#define rfore(i,n)  for(int i=n;i>=1;i--)
#define CASE(t) cout<<"Case #"<<(t)<<": ";
#define INF 1020000000
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define print(x)    for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<endl;
#define printii(x)  for(auto it=x.begin();it!=x.end();it++) cout<<it->F<<' '<<it->S<<endl;  
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll dp[3005][3005];
int main()
{
	int n,s;
	cin>>n>>s;
	ll ans=0;
	vi a(n);
	forl(i,n)	cin>>a[i];
	dp[n][0]=1;
	for(int i=n-1;i>=0;i--)
	{
		for(int x=0;x<=s;x++)
		{
			dp[i][x]=dp[i+1][x];
			if(x==a[i])
				dp[i][x]=(dp[i][x]+n-i)%MOD;
			else if(x>a[i])
				dp[i][x]=(dp[i][x]+dp[i+1][x-a[i]])%MOD;
		}
		// forl(x,s+1)
		// {
			// cout<<dp[i][x]<<' ';
		// }
		// cout<<endl;
		ans+=dp[i][s];
		// cout<<ans<<endl;
		ans%=MOD;
	}
	cout<<ans<<endl;

}