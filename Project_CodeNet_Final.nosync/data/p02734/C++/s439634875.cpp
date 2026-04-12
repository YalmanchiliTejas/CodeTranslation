    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    using namespace std;
    using namespace __gnu_pbds;
    #define ll long long
    #define int long long
    #define pb push_back
    #define For(i,n) for(ll  i=0;i<n;i++)
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;clock_t clk = clock();
    #define f(a,b,c) for(ll a=b;a<c;a++)
    #define mod   998244353
    #define ld long double
    #define read(t) ll t;cin>>t;
    #define all(x) x.begin(),x.end()
    #define fi first
    #define se second
    #define endl "\n"
    #define pii pair<ll,ll>
    #define what_is(x) cerr << #x << " is " << x << endl;
    #define time cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    const double pi=3.14159265358979323846264;
    typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;

/**********************************************************************************************************************/
const ll man=3005;
ll dp1[man][man];
ll dp2[man][man];
ll dp3[man][man];
signed main()/*Check flow...question galat mat padhna */
{
    fast;   
    dp1[0][0]=1;
	ll n,s;
	cin>>n>>s;
	ll a[n];
	For(i,n)
	{
		cin>>a[i];
	}
	For(i,n)
	{
		for(ll sum=0;sum<=s;sum++)
		{
			dp1[i+1][sum]=(dp1[i+1][sum]+dp1[i][sum])%mod;
			dp2[i+1][sum]=(dp2[i+1][sum]+dp1[i][sum]+dp2[i][sum])%mod;
			dp3[i+1][sum]=(dp3[i+1][sum]+dp1[i][sum]+dp2[i][sum]+dp3[i][sum])%mod;
			if(sum+a[i]<=s)
			{
				dp2[i+1][sum+a[i]]=(dp2[i+1][sum+a[i]]+dp1[i][sum]+dp2[i][sum])%mod;
				dp3[i+1][sum+a[i]]=(dp3[i+1][sum+a[i]]+dp1[i][sum]+dp2[i][sum])%mod;
			}
		}
	}
	cout<<dp3[n][s]<<endl;
}      