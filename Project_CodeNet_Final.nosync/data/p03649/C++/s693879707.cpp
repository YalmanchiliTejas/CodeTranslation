#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll a[n];
	for(int i = 0; i<n; i++)
		cin>>a[i];
	sort(a,a+n,greater<ll>());
	ll cnt = 0;
	while(a[0]>=n)
	{
		for(int i = 0; i<n; i++)
		{
			ll g = a[i]/n;
			cnt += g;
			a[i] = a[i]%n;
			for(int j = 0; j<n; j++)
				if(j!=i)
					a[j] += g;
		}
		sort(a,a+n,greater<ll>());
	}
	cout<<cnt<<endl;
	return 0;
}