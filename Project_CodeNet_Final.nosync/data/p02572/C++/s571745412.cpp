#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
// int ans(){
    
// }
 
int main() {
	ll n;
    cin>>n;
    ll a[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        ans=ans%mod + ((a[i]%mod)*((sum)%mod))%mod;
    }
    cout<<(ans%mod);
}