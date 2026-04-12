#include<bits/stdc++.h>
#define ll          long long int
#define lld          long double
#define pb          push_back
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define vec         vector<ll>
#define all(a)     (a).begin(),(a).end()
#define F           first
#define S           second
#define mod         1000000007
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define pit         pair<ll,ll>::iterator
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
ll xo(ll x, ll y) 
{ 
   return (x | y) & (~x | ~y); 
}  
ll bin_Expo(ll x,ll n)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return bin_Expo(x*x,n/2);
    else                             //n is odd
        return x*bin_Expo(x*x,(n-1)/2);
}
ll mod_Expo(ll x,ll n,ll M)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return mod_Expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*mod_Expo((x*x)%M,(n-1)/2,M))%M;
 
}
ll NcR(int n, int r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m=__gcd(p, k); 
            p /= m; 
            k /= m; 
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
}
bool prime_check(ll x)
{
    bool prime = (x >= 2);
    for (ll i = 2; i * i <= x; i++) 
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
}
ll logg(ll base,ll x)
{
    return (ll)(log(x)/log(base));
}
ll n,a[3001],k,dp[3001][3001][2];
ll f(ll st,ll ed,ll p)
{
	if(st>ed)
	return 0;
	if(dp[st][ed][p]!=-1)
	return dp[st][ed][p];
	if(st==ed)
	return dp[st][ed][p]=p==0?a[st]:-1*a[st];
	if(p==0)
		return dp[st][ed][p]=max(a[st]+f(st+1,ed,1),a[ed]+f(st,ed-1,1));
	else
		return dp[st][ed][p]=min(f(st+1,ed,0)-a[st],f(st,ed-1,0)-a[ed]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout<<setprecision(12)<<fixed;
	int TESTS=1;
//	cin>>TESTS;
    while(TESTS--)
    {
    	ll i,j,l,m,k;
    	cin>>n;
    	rep(i,0,n)
    	cin>>a[i];
    	repi(i,0,n)
    	{
    		repi(j,0,n)
    		{
    			rep(k,0,2)
    			dp[i][j][k]=-1;
			}
		}
		cout<<f(0,n-1,0);
    } 
	return 0;
}