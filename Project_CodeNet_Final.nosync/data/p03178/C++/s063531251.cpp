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
#define N         100005
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
ll no(char xx)
{
	return xx-'0';
}
ll n,D; string y;
//ll count(ll i,ll sum_so_far,ll leftmost_lo,ll leftmost_hi)
//{
//	if(i==n)
//	{
//		if(sum_so_far%4==0 && leftmost_lo<=leftmost_hi)
//		return 1;
//		return 0;
//	}
//	ll l1,l2,ans=0;
//	repi(j,0,9)
//	{
//		l1=leftmost_lo; l2=leftmost_hi;
//		l1=(no(y[i])>j)?min(l1,i):l1;
//		l2=(no(y[i])<j)?min(l2,i):l2;
//		ans+=count(i+1,sum_so_far+j,l1,l2);
//		ans=ans%mod;
//	}
//	return ans;
//}
ll dp[10005][100][2];
ll count1(ll i,ll sum_so_far,ll x)
{
	if(i==n)
	{
		return dp[i][sum_so_far%D][x]=((sum_so_far%D==0) ? 1 : 0 );
	}
	if(sum_so_far>=D)
	sum_so_far=sum_so_far%D;
	ll ans=0,z;
	if(dp[i][sum_so_far][x]!=-1)
	return dp[i][sum_so_far][x];
	z= x ? 9ll : no(y[i]) ;
	repi(d,0,z)
	{
		ans+=count1(i+1, (sum_so_far+d)%D, x || (d<no(y[i])));
		ans=ans%mod;
	}
	return dp[i][sum_so_far][x]=ans;
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
    	ll i,j,l,m,first,last,x;
    	cin>>y;
    	cin>>D;
    	n=y.size();
    	repi(i,0,n)
    	{
    		rep(j,0,100)
    		{
    			rep(k,0,2)
    			dp[i][j][k]=-1;
			}
		}
		x=count1(0,0,0);
		x=(x-1+mod)%mod;
		cout<<x;
	}
	return 0;
}