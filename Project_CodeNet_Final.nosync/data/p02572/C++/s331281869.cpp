#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Scenario #"<<x<<": "
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = LLONG_MAX;
const int N = 18;


void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;

	ll sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ans = (ans % mod + (a[i] * sum) % mod) % mod;
		sum = (sum + a[i]) % mod;
	}

	cout << ans % mod << endl;



}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);




	int t = 1;
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}