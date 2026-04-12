#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(ll i=a; i<b; i++)
#define revloop(i,a,b) for(ll i=a; i>=b; i--)
#define pb push_back
#define vl vector<ll>
#define vvl vector<vl>
#define pl pair<ll,ll>
#define vpl vector<pl>
#define all(c) (c).begin(), (c).end()
#define sz(a) ((a).size())
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i!=(c).end(); i++))
#define mp make_pair
#define ss second
#define ff first
#define ld long double
const ll INF = 1e13;
const ll N = 1e4+5, D=105;
const ll mod= 1e9+7;
/*bool prime(ll x)
{
	if(x<2) return false;
	for(ll i=2; i*i<=x; i++) if(x%i==0) return false;
	return true;
}
vl fac(N);
void fact()
{
	fac[0]=1;
	loop(i,1,N) fac[i]=(fac[i-1]*i)%mod;
}
*/
string s;
ll d,n,dp[N][D][2];
ll f(ll i, ll sum, bool flag)
{
	if(i==n) return sum==0;
	if(dp[i][sum][flag]!=-1) return dp[i][sum][flag];
	ll &ans = dp[i][sum][flag];
	ans = 0;
	ll l = 0, r=9;
	if(!flag) r = (s[i]-'0');
	loop(dig,l,r+1)
	{
		ll nsum = sum+dig;
		nsum%=d;
		bool nflag = flag||(dig<(s[i]-'0'));
		ans = ans+f(i+1,nsum,nflag);
		ans%=mod;
	}
	return ans;
}
void solve()
{
 cin>>s>>d;
 n=s.size();
 memset(dp,-1,sizeof(dp));
 cout<<(f(0,0,0)-1+mod)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--) solve();
 return 0;
}