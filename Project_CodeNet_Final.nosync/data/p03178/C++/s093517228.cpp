#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
string k;
const ll L = 1e4 + 5;
ll dp[L][3][105], d;
ll rec(ll n, ll f, ll m)
{
	ll i;
	if(n == sz(k))
	{
		if(m == 0)
			return 1;
		return 0;
	}
	if(dp[n][f][m] != -1)
		return dp[n][f][m];
	ll l = 9;
	if(f)
		l = k[n] - '0';
	ll ans = 0;
	for(i=0;i<=l;i++)
	{
		ll nf;
		if(i < k[n] - '0')
			nf = 0;
		else
			nf = f;
		ans += rec(n+1,nf,(m+i)%d) % mod;
	}
	return dp[n][f][m] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> k >> d;
	ll i,j,p;
	for(i=0;i<=sz(k);i++)
		for(j=0;j<2;j++)
			for(p=0;p<d;p++)
				dp[i][j][p] = -1;
	cout << (mod + rec(0,1,0) - 1) % mod << endl;
	return 0;
}