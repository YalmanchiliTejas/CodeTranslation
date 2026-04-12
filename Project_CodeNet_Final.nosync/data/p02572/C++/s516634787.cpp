#include <iostream>
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define li long ll
#define pp pair<ll, ll>
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
#define pb push_back
#define llp(i, x, n) for (ll i = x; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fr first
#define ss second
#define mod 1000000007
using namespace std;
ll sum(ll a[], ll n) 
{ 
    ll b[n];
    b[0]=a[0];
    for(int i=1;i<n;i++)
    {
    	b[i]=a[i]+b[i-1];
    }
    ll sum=0;
    for(int i=0;i<n-1;i++)
    {
    	sum=sum%mod+(a[i]%mod)*((b[n-1]-b[i])%mod);
    	sum=sum%mod;
    }
    return sum;
} 
int main()
{
	fast;
    ll n;
    cin>>n;
    ll a[n];
    llp(i,0,n)
    cin>>a[i];
    cout<<sum(a,n)%mod<<endl;
}