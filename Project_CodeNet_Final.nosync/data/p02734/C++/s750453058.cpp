#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,s,ans=0,mod=998244353;cin>>n>>s;
  lvector A(n,0);rep(i,n) cin>>A[i];
  lvector f(s+1,0);
  for(ll a:A) {
    f[0]+=1;
    lvector f_;
    for(ll i=0;i<=s-a;++i) f_.emplace_back(f[i]);
    for(ll i=a;i<=s;++i) f[i]+=f_[i-a];
    rep(i,s+1) f[i]%=mod;
    ans+=f[s];
  }
  ans%=mod;
  print(ans);
  return 0;
}