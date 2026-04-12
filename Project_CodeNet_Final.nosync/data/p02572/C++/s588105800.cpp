// Starting with the name of Allah

#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define Nayon ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define gcd(a,b)         __gcd(a,b)
#define lcm(a,b)         (a/gcd(a,b))*b
#define v_sum(a)         accumulate(a.begin(),a.end(),0)
#define v_max(a)         *max_element(a.begin(),a.end())
#define v_min(a)         *min_element(a.begin(),a.end())
#define v_uni(a)         a.erase(unique(a.begin(),a.end()),a.end())

using namespace std;



const ll mod=1000000007;

int main()
{
	Nayon;
	ll n,i,j,sum=0,x=0;
	cin>>n;
	ll a[n+1];
	for(i=0;i<n;i++){
		cin>>a[i];
		x+=a[i];
	}
	for(i=0;i<n;i++){
		x-=a[i];
		sum=(sum+((x%mod)*a[i])%mod);
		sum%=mod;
	}
	cout<<sum<<nl;
	return 0;
}

//Happy Coding.........