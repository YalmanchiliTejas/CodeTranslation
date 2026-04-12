//Author : Gaara
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define endl "\n"
#define fo(i,n) for(ll i=0;i<n;i++)
#define ro(i,n) for(ll j=n-1;i>=0;i--)
#define vll vector<long long>
#define mod 1000000007
 
int main(){
    int t=1;
    //cin>>t;
    while(t--){
	  ll n; cin>>n;
      ll a[n];
      fo(i,n) cin>>a[i];
      ll sum[n];
      sum[n-1] = a[n-1];
      for(int i=n-2;i>=0;i--){
        sum[i] = (sum[i+1] + a[i])%mod;
      }
      ll ans = 0;
      for(int i=0;i<n-1;i++){
        ans+= (a[i]*sum[i+1])%mod;
        ans %= mod;
      }
      cout<<ans<<endl;
    }
    return 0;
}