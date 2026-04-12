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
 ll t;
  cin>>t;
  if(t>=30)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}