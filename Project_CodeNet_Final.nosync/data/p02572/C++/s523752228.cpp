#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define scan(a,n) for(long int index=0;index<n;index++) cin>>a[index];
#define print(a,n) for(long int index=0;index<n;index++) cout<<a[index]<<" ";cout<<endl;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vli vector<long long int>
#define vlli vector<pair<long long int,long long int>>
#define vsi vector<string>
#define vci vector<char>
#define all(n) (n.begin(),n.end())


 
int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    ll t;
    t=1;
    while(t--){
      ll n;
      cin>>n;
      ll a[n],i;
      scan(a,n);
      ll sum=0;
      for(i=0;i<n;i++){
        sum+=a[i];
        sum%=mod;
      }
      ll ans=0;
      for(i=0;i<n;i++){
        sum-=a[i];
        if(sum<0) sum+=mod;
        ans+=(sum*a[i])%mod;
        ans%=mod;
      }
      cout<<ans%mod<<endl;
      }
return 0;    
 }  