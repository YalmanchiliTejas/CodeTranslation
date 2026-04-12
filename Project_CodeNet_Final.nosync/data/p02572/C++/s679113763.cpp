#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,k,n) for(ll i = k;i<n;i++)
#define mo map<ll,ll> 
#define mod 1000000007
int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll n;
   cin>>n;
   ll arr[n+2];
   fr(i,0,n){
   	cin>>arr[i];
   }
   ll suf[n+4];
   memset(suf,0,sizeof(suf));
 for(ll i = n-1;i>=0;i--){
 	suf[i] += suf[i+1];
 	suf[i] += arr[i];
 }
 ll ans = 0;
 fr(i,0,n){
ans += ((arr[i]%mod)*((suf[i+1])%mod))%mod;

 }
 ans %= mod;
 cout<<ans<<"\n";
}