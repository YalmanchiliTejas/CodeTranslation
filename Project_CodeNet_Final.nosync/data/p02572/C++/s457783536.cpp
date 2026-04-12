#include <bits/stdc++.h>
#define ll long long
#define foi(n) for(ll i=0;i<n;i++)
using namespace std;
int main(){
 
  ll n;
  cin>>n;
  ll a[n];
  foi(n)
  cin>>a[i];
  ll acc=accumulate(a,a+n,0LL);
  ll ans=0;
  ll b[n];
  b[0]=0;
  foi(n-1){
  	b[i+1]=b[i]+a[i];
  	b[i+1]%=1000000007;
  }
  foi(n){
  	ans+=(a[i]*(b[i]));
  	ans%=1000000007;
  }
  cout<<ans<<endl;
  
}