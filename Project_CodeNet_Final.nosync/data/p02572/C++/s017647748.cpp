#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007

int main() {
    fastio
	ll n,t,i,j,x,k;
    cin>>n;
    
    ll a[n],b[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    
    b[n-1]=a[n-1];
    
    for(i=n-2;i>=0;i--)
    b[i]=(a[i]+b[i+1])%mod;
    
    ll ans=0;
    
    for(i=0;i<n-1;i++)
    ans=(ans+a[i]*b[i+1])%mod;
    cout<<ans%mod;
    
	return 0;
}