#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define mod 1000000007
int main(){
    ll n;
    cin>>n;
    vector<int> arr(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        
    }
    ll ans=0;
    for(ll i=n-1;i>=0;i--){
        ans=(ans+arr[i]*(sum))%mod;
        sum=(sum+arr[i])%mod;
    }
    cout<<ans<<endl;
}
