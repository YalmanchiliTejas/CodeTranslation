#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define mod ((ll)1e9+7)
#define maxx ((ll)1e6+5)
#define pb push_back
#define ins insert
#define usefile freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
ll exp(ll x,ll y,ll p){ ll res=1; while(y) {if(y%2) res=(res*x%p)%p; x=(x*x)%p; y/=2; } return res;}
ll expo(ll x,ll y){ ll res=1; while(y) {if(y%2) res=(res*x%mod)%mod; x=(x*x)%mod; y/=2; } return res;}
/*int sv[1000000]={0};
ll fact[1000007]={0};
void facto() {fact[0]=1;fact[1]=1;for(int i=2;i<100007;i++)fact[i]=(fact[i-1]*i)%mod;}
void sve() {sv[0]=1;sv[1]=1;for(int i=2;i*i<=maxx;i++){if(!sv[i]){for(int j=2*i;j<=maxx;j+=i)sv[j]=1;}}}//0 hai to prime
ll ncr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(expo(fact[r],mod-2)))%mod; res=(res*(expo(fact[n-r],mod-2)))%mod; return res;}
ll npr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(expo(fact[n-r],mod-2)))%mod; return res;}*/
using namespace std;
int a[3003+1];
int d[3003][3003];
bool dd[3003][3003];
int n;
int f(int l, int r)
{
	int done = n-r+l-1;
	int ans;
	if(dd[l][r])
		return d[l][r];
	if(l == r)
	{
		if(done % 2)
			ans = -1 * a[l];
		else ans = a[l];
	}
	else
	{
		if(done % 2)
			ans = min(f(l+1 , r) - a[l] , f(l , r-1) - a[r]);
		else ans = max(f(l+1 , r) + a[l] , f(l , r-1) + a[r]);
	}
	d[l][r] = ans;
	dd[l][r] = 1;
	return ans;
}
signed main()
{
	int i, j, k;
	cin >> n;
	for(i=1 ; i<=n ; i++)
		cin >> a[i];
	cout << f(1,n) << "\n";
	return 0;
}
