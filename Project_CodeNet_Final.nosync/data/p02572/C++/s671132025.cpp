#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio (false) ;cin.tie(NULL);
#define tc  int t;cin>>t;for(int i=0;i<t;i++)
#define ll long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define um(a,b) unordered_map<a,b>
#define vv(a) vector<a>
#define pp(a,b) pair<a,b>
ll power(ll a,ll b,ll mod){  ll ans=1;  while(b>0){
  if(b&1){ ans=(ans*a)%mod;} a=(a*a)%mod;  b=b/2; } return ans;}

int main(){
FIO
 ll n;
 cin>>n;
 ll mod=pow(10,9)+7;
 ll a;
 ll sum1=0;
 ll sum2=0;
 for(ll i=0;i<n;i++){
    cin>>a;
    sum1=(sum1+a)%mod;
    ll x=power(a,2,mod)%mod;
    sum2=(sum2+x)%mod;
 }
// cout<<sum1<<" "<<sum2<<endl;
 sum1=power(sum1,2,mod);

 ll temp=power(2,mod-2,mod);
 //cout<<temp<<endl;
 ll ans=(sum1-sum2+2*mod)%mod;
 ans=(ans*temp)%mod;
 cout<<ans<<endl;
}
