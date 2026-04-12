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
#define nmod         -1000000007
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define pit         pair<ll,ll>::iterator
#define xxx         exit(0);
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
string k; ll d,n, dp[10005][105][2];
ll cc(ll ind,ll sum, ll p)
{
	if(ind==n && sum==0) return 1;
	if(ind>=n && sum!=0) return 0;
	if(dp[ind][sum][p]!=-1) return dp[ind][sum][p];
	ll x = (p==1)?9:(k[ind]-'0');
	ll ans=0;
	repi(i,0,x)
	{
		ans = ( ans + cc(ind+1, (sum+i)%d, (p==1) || (i < (k[ind]-'0'))) )%mod;
	}
	return dp[ind][sum][p] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS; 
    while(TESTS--)
    {
    	cin>>k;
    	cin>>d;
    	n=k.size();
    	repi(i,0,n)
    	{
    		repi(j,0,d)
    		{
    			dp[i][j][0]=-1; dp[i][j][1]=-1;
			}
		}
    	cout<<(cc(0,0,0)-1+mod)%mod;
	}
	return 0;
}