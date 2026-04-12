#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define ll long long
#define ld long double
#define pb push_back
#define FR first
#define SC second
#define MOD 1000000007
#define LLMN LONG_LONG_MIN
#define LLMX LONG_LONG_MAX
#define LDMX LDBL_MAX
#define LDMN LDBL_MIN
#define MAX 1000000
#define pll pair<ll, ll>
#define vl vector<ll>
#define vll vector< vl >
#define vb vector<bool>
#define vbb vector< vb >
#define vpl vector<pll>
#define vpll vector< vpl >

void solve()
{
    ll n;
    cin>>n;
    vl a(n);
    for(ll i = 0; i < n; i++) cin>>a[i];
    ll sum = 0;
    vl suff(n, 0);
    for(ll i = n - 2; i >= 0; i--)
        suff[i] = (suff[i + 1] + a[i + 1]) % MOD;
    //for(auto i : suff)
    //    cout<<i<<" ";
    for(ll i = 0; i < n; i++)
    {
        sum = (sum + (a[i] * suff[i]) % MOD) % MOD;
    }
    cout<<sum;
    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t = 1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
