#include <bits/stdc++.h>
using namespace std;
#define ll long long int
# define m 1000000007
int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	
	ll n;
	cin>>n;
	ll a[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
	    cin>>a[i];
	    sum+=a[i];
	}
	
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
	    sum-=a[i];
	    ans+=(((sum%m)*(a[i]%m))+m)%m;
	    ans=ans%m;
	}
	cout<<ans<<endl;
	
	return 0;
}
