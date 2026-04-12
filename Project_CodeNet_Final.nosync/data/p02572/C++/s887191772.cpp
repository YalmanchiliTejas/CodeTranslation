#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
int main(void){
    // Your code here!
 ll i,ans,n,s;
 ans=s=0;
 cin >> n;
 ll a[n];
 for(i=0;i<n;i++)
 {
  cin >> a[i];
  s+=a[i];
 }
 for(i=0;i<n;i++)
 {
  s-=a[i];
  ans=(ans+(((s%mod)*(a[i]%mod))%mod))%mod;
 }
 cout << ans;
 return 0;
}