#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

/*
cout<<"\ndebugging\n";
*/

int main()
{
	ios_base::sync_with_stdio(false); 	//Fast I/O
    cin.tie(NULL);
    
	ll t,n,i,j;
	cin>>n;
	vector<ll> a;
	ll x;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	ll sum=0,sumall=0;
	for(i=n-2;i>=0;i--)
	{
		sumall=(sumall + a[i+1])%mod;
		sum= (sum + (a[i]*sumall)%mod)%mod;
	}	
	cout<<sum;
	return 0;
}
