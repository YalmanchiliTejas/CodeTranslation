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
const ll N = 301;
const ll mod= 1000000007;
bool prime(ll x)
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

void solve()
{
  ll n; 
  cin>>n;
  vl a(n);
  loop(i,0,n) cin>>a[i];
  ll dp[n][n];
  revloop(l,n-1,0)
   loop(r,l,n)
   {
   	if(l==r) dp[l][r] =  a[l];
   	else dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
   }
   cout<<dp[0][n-1]<<endl;
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