#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
   int n;
   cin>>n;
   ll arr[n];
   ll sum=0;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       sum=sum+arr[i];
       sum%=mod;
   }
   ll ans=0,pref=0;
   for(int i=0;i<n;i++){
       pref+=arr[i];
       pref%=mod;
       ans+=arr[i]*(sum-pref+mod)%mod;
       ans%=mod;
   }
   cout<<ans;
}