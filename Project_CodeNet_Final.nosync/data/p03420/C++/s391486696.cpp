#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);


int main(){
  ll n,k;
  ll ans=0;
  cin >> n >> k;
  if(k==0){
    ans=n*n;
    cout<<ans<<endl;
    return 0;
  }
  for(ll b=k+1;b<=n;b++){
    ans+=(n/b)*max(0ll,b-k)+max(0ll,n%b-k+1);
  }
  cout << ans << endl;
}
