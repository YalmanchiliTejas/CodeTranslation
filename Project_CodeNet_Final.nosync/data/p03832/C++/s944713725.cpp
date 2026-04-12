#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>   
using namespace std;
using namespace __gnu_pbds;
typedef long long ll; 
#define int long long
typedef unsigned long long lu;
typedef vector<ll> v;
typedef vector<vector<ll> > vv;
typedef vector<string>  vs;
typedef vector<pair<ll,ll>> vpr;
typedef long double ld;
#define f(i,n) for(ll i = 0; i < n; i++)
#define ff(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define amax(x,y) if(y>x) x=y;
#define amin(x,y) if(y<x)x=y;
#define bg(x) x.begin()
#define sz(x) (ll)x.size()
#define in(x,n) for(ll i=0;i<n;i++)cin>>x[i]
#define out(x,n) for(ll i=0;i<n;i++)cout<<x[i]<<" " 
#define mxt(a) *(max_element(a.begin(),a.end()))
#define mnt(a) *(min_element(a.begin(),a.end())
#define tc ll t;cin>>t;while(t--)
typedef pair<ll,ll> pi;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define yesno(f) if(f) yes else no
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
const ll mod=1e9+7;
const ld PI = 2 * acos(0.0);
ll m(ll a){ return (a+mod)%mod;}
ll cel(ll x1,ll y1){if((x1%y1)==0)return x1/y1;else return x1/y1+1;}
ll power(ll a,ll b,ll m)
{
	if(b==0)
		return 1;
	ll d=power(a,b/2,m);
	d=(d*d)%m;
	if(b&1)
		d=(d*a)%m;
	return d;
}
// set_name.find_by_order(k) It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time
// set_name.order_of_key(k) It returns to the number of items that are strictly smaller than our item k in O(logn) time.
/*string operations :
str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
str.substr (x) : returns a substring str[x],... end of string
str.find(qtr) : returns the first occurenece of qtr in str */

int solve(){}
int dp[2000][2000],p[2000][2000],fact[2000],ncr[2000][2000];
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // int tt=1;
    //tc{

    //	cout<<"Case #"<<tt++<<": "<<solve()<<endl;
    //}

	int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
	fact[0]=1;
	for(int i=1;i<=n;i++)
		fact[i]=(fact[i-1]*i)%mod;

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j+=i)
		{
			int denom=(power(fact[i],j/i,mod)*fact[j/i])%mod;
			denom=power(denom,mod-2,mod);
			p[i][j]=(fact[j]*denom)%mod;

		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int denom=power((fact[j]*fact[i-j])%mod,mod-2,mod);
			ncr[i][j]=(fact[i]*denom)%mod;
		}
	}
	// return 0;

	// p[b][0]=1;
	dp[b+1][0]=1;
	for(int i=b;i>=a;i--)
	{
		for(int j=0;j<=n;j++)
		{
			for(int x=0;x<=j;x+=i)
			{
				int nn=x/i;
				if((nn <=d && nn >=c)  || nn==0){
					int ans=(p[i][x]*dp[i+1][j-x])%mod;
					ans*=ncr[j][x];
					if(ans  > mod)
						ans%=mod;
					dp[i][j]+=ans;
					if(dp[i][j] > mod)
						dp[i][j]%=mod;
				}
			}
		}
	}
	cout<<dp[a][n]<<endl;
	return 0;
}