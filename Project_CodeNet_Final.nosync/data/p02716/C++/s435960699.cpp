#include <bits/stdc++.h>
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;
 
ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
ll mod(ll a, ll b) {return (a % b + b) % b;}
using namespace std;

ll powerm(ll base,ll exp,ll mod) 
{ll ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}

void solve()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1; i < n+1; i++) cin >> a[i];
    ll ps[n+1]={0},dp[n+1]={0};
    dp[0] = 0;
	dp[1] = 0;
    ps[1] = a[1];
    for(ll i=3;i<=n;i+=2) 
	{
		ps[i] = ps[i-2] + a[i];
	//	cout << ps[i] << " ";
	}
    for(ll i = 2; i < n+1; i++)
	{
        if (i&1)
		{
            dp[i] = max(dp[i-1],a[i]+dp[i-2]);
        }
        else
		{
            dp[i] = max(dp[i-2] + a[i],ps[i-1]);
        }
	}
    cout << dp[n] << endl;
}
int main() 
{  
	fast;
	solve();
}