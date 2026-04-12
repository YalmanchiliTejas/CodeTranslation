#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=998244353;

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j;
  ll n,s;
  cin>>n>>s;
  ll a[n+1];
  VI v(3030,0);
  for(i=1;i<=n;i++) {
    cin>>a[i];
  }
  ll ans=0;
  for(i=1;i<=n;i++){
    for(j=s-a[i];j>=1;j--){
      if(j+a[i]==s) {
        ans+=v[j]*(n+1-i);
        ans%=mod;
      }
      v[j+a[i]]+=v[j];
      v[j+a[i]]%=mod;
    }
    v[a[i]]+=i;
    if(a[i]==s) {
        ans+=i*(n+1-i);
        ans%=mod;
    }
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;

}