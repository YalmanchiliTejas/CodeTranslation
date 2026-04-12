#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,s,ans=0,mod=998244353;cin>>n>>s;
  lvector A(n),f(3010,0);rep(i,n) cin>>A[i];
  for(ll a:A) {
    f[0]+=1;
    lvector ff;
    rep(i,s-a+1) ff.emplace_back(f[i]);
    rep(i,s-a+1) f[i+a]+=ff[i];
    rep(i,s+1) f[i]%=mod;
    ans=(ans+f[s])%mod;
  }
  print(ans);
  return 0;
}