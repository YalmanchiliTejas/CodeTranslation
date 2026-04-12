#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

#define deb(x) cerr<<#x<<":"<<x<<"\n";
#define dvi(x) for(ll i=0;i<x.size();i++)cerr<<#x<<"["<<i<<"]:"<<x[i]<<" ";
#define iter(v) for(auto it:v)
#define wt ll t;cin>>t;while(t--)
#define rl(x) ll x;cin>>x;
#define rvi(x,n) vi x(n);for(ll i=0;i<n;i++) cin>>x[i];
#define rs(x) string x;cin>>x;
#define wvi(x) for(ll i=0;i<x.size();i++) cout<<x[i]<<" ";cout<<endl;
#define ws(x) cout<<x<<endl;
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
#define pll pair<ll, ll>
#define fo(i,n) for(ll i=0;i<n;i++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define decsort(b) sort(all(b),greater<ll>())
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
const ll N = 1e9+7;

map<long long, long long> factorize(long long n) {	//returns map containing factor and multiplicity, Eg: 60 = {{2,2},{3,1},{5,1}}
	map<long long, long long> ans;
	for (long long i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ans[i]++;
			n /= i;
		}
	}
	if (n > 1) {
		ans[n]++;
		n = 1;
	}
	return ans;
}

void FAST() {	//FAST Input Output, DONT use both scnaf,prllf / cin,cout , Use any ONE system
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll answer(ll sum,vvi a,ll n,ll m)
{
	ll cnt1=0,cnt0=0;
	for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{
				if(i+j==sum || i+j==n+m-2-sum)
				{
					if(a[i][j])cnt1++;
					else cnt0++;
				}
			}
		}
	return min(cnt0,cnt1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	FAST();
 	rl(n)
	rvi(a,n)
	vi pre(n);
	pre[0]=a[0];
	for(ll i=1;i<n;i++)
	{
		pre[i]+=pre[i-1]+a[i];
		pre[i]%=N;
	}
	ll ans=0;
	for(ll i=1;i<n;i++)
	{
		ans+=(pre[i-1]*a[i])%N;
		ans%=N;
	}
	cout<<ans;
}