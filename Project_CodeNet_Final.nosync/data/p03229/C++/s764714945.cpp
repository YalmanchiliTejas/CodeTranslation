//Rishabh Sethi @lostground97

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define in insert
#define mod 1000000007
#define vpair vector< pair <ll,ll> >
#define F first
#define S second

ll modexp(ll x, ll y)
{
	ll ans = 1;
	x = x%mod;
	while(y>0)
	{
		if(y%2==1)
			ans = (ans%mod*x%mod)%mod;
		y = y/2;
		x = (x%mod*x%mod)%mod;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<ll> v;
	for(int i=0; i<n; i++)
	{
	    ll x;
	    cin>>x;
	    v.pb(x);
	}
	sort(v.begin(), v.end());
	ll l = v[0], r = v[n-1];
	ll ans = (r-l);
	ll i = 1;
	ll j = n-2;
	while(i<=j)
	{
	    ll p = v[i];
	    ll q = v[j];
	    ll a1 = max(abs(l-p),abs(r-p));
	    ll a2 = max(abs(l-q),abs(r-q));
	    if(a1>=a2)
	    {
	        ans += a1;
	        if(abs(l-p)>=abs(r-p))
	        {
	            l = p;
	        }
	        else
	        {
	            r = p;
	        }
	        i++;
	    }
	    else
	    {
	        ans += a2;
	        if(abs(l-q)>=abs(r-q))
	        {
	            l = q;
	        }
	        else
	        {
	            r = q;
	        }
	        j--;
	    }
	}
	cout<<ans<<endl;
}