#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum=0;
  ll p=1e9+7;
  for(ll i=0;i<n;i++){
    cin >> a.at(i);
    if(i==0){
      continue;
    }
    sum+=a.at(i);
    sum%=p;
  }
  ll ans=0;
 for(ll i=0;i<n-1;i++){
    ans+=sum*a.at(i);
    sum=sum-a.at(i+1);
   if(sum<0){
     sum=sum+p;
   }
    ans=ans%p;
  }
  cout << ans;
}