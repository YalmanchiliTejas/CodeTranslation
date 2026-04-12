#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll n, k;
  cin>>n>>k;

  if(!k) cout<<n*n<<endl;
  else {

    ll ans=0;
    for(ll b=1;b<=n;b++){
      if(b <= k) continue;
      ll t = n/b;
      ans += (b - k) * t;
      ans += max(n%b-k+1,0LL);
    }
    cout<<ans<<endl;

  }
  return 0;
}
