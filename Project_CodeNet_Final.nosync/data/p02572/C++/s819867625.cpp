#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define mod 1000000007
#define PI 3.1415926535
using namespace std;
ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return power(x, y / 2) * power(x, y / 2);
	else
		return x * power(x, y / 2) * power(x, y / 2);
}
ll modExpo(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modExpo((x*x)%mod,n/2);
    else                            
        return (x*modExpo((x*x)%mod,(n-1)/2))%mod;
 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	ll n;
	cin>>n;
	ll a[n],i,s=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
		s%=mod;
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		s-=a[i];
		if(s<0)
			s+=mod;
		ans+=a[i]*s;
		ans%=mod;
	}
	cout<<ans<<endl;
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}