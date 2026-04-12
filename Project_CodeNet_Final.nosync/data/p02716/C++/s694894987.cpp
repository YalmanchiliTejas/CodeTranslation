#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define imx INT_MAX
#define imn INT_MIN
#define llmx LLONG_MAX
#define llmn LLONG_MIN

#define fi first
#define se second
#define pb push_back



/////////////////////GCD//////////////////////
ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

////////////////////SIEVE OF ERATOSTHENES//////////////////////
vector<int> sieveoferatosthenes(int n)
{
	vector<bool> prime(n+1, true);
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(prime[i])
		{
			for(int j = i*i; j<=n; j+=i)
			{
				prime[j]=false;
			}
		}
	}
	vector<int> all_primes;
	for(int i = 2; i <=n; i++)
	{
		if(prime[i]) all_primes.pb(i);
	}
	return all_primes;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		// cout<<a[i]<<" ";
	}
	cout<<endl;
	// if(n%2==0)
	// {
	// 	ll sum1=0, sum2=0;
	// 	for(int i = 0; i<n; i++)
	// 	{
	// 		if(i%2==0)
	// 			sum1+=a[i];
	// 		else sum2+=a[i];
	// 	}
	// 	cout<<max(sum1, sum2)<<endl;
	// }
	// else
	// {
		vector<ll> p(n+1, 0), dp(n+1, 0);
		for(int i = 1; i <= n; i++)
		{
			p[i] = p[max(0, i-2)]+a[i-1];
		}
		// for(int i:p) cout<<i<<"  ";
			// cout<<endl;
		for(int i = 2; i <= n; i++)
		{
			if(!(i%2))
			{
				dp[i]=max(dp[i-2]+a[i-1], p[i-1]);
			}
			else dp[i]=max(dp[i-2]+a[i-1], dp[i-1]);
		}
		cout<<dp[n]<<endl;
	// }
}