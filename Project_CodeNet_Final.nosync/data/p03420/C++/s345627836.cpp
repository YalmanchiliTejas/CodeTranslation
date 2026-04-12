#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n,k;
  cin >> n >> k;
  
  ll ans=0;
  for(int i=1; i<=n; i++){
    ll b = i;
    ll r = (n+1)%b;
    ll p = (n+1)/b;
    ans+=p*max((ll)0,b-k);
    ans+=max((ll)0,r-k);
  }
  
  if(k==0) ans-=n;
  cout << ans << endl;
}
  
  
