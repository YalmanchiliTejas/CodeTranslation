#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59

int main(){
  ll i,j;
  ll n,k;
  cin>>n>>k;
  if(k==0) {
    cout<<n*n<<endl;
    return 0;
  }
  ll ans=0;
  for(i=k+1;i<=n;i++){
    j=n/i;
    ans+=(i-k)*j;
    ans+=max(0ll,n-i*j-k+1);
  }
  cout<<ans<<endl;
  return 0;

}