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
#define xxx         exit(0);
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
ll logg(ll base,ll x) {
    return (ll)(log(x) / log(base));
}
ll a[3005],dp[3005][3005][2]; ll n;
ll E(ll st, ll ed, ll p)
{
	if(st==ed)
	{
		if(p==1) return dp[st][ed][p] = -1*a[st];
		else return dp[st][ed][p] = a[st];
	}
	if(dp[st][ed][p] != -1) return dp[st][ed][p];
	ll ans=0;
	if(p)
		ans=min(-1*a[st]+E(st+1,ed,!p),-1*a[ed]+E(st,ed-1,!p));
	else
		ans=max(a[st]+E(st+1,ed,!p),a[ed]+E(st,ed-1,!p));
	return dp[st][ed][p]=ans;
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
    	ll i,j,k,l,m,h,w,val;
    	cin>>n;
    	rep(i,0,n) cin>>a[i];
		repi(i,0,n){
			repi(j,0,n) { dp[i][j][0]=-1; dp[i][j][1]=-1;}
		} 
		cout<<E(0,n-1,0);
	}
	return 0;
}
