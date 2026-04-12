#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

ll n;
lvector layer(n+1),pat(n+1);

ll f(ll a,ll b) {
  if(a==0) return (b<=0)?0:1;
  else if(b<=1+layer[a-1]) return f(a-1,b-1);
  else return pat[a-1]+1+f(a-1,b-2-layer[a-1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,x;cin>>n>>x;
  layer.resize(n+1),pat.resize(n+1);
  layer[0]=1,pat[0]=1;
  for(ll i=1;i<=n;++i) {
    layer[i]=1+layer[i-1]+1+layer[i-1]+1;
    pat[i]=pat[i-1]+1+pat[i-1];
  }
  ll ans=f(n,x);
  print(ans);
  return 0;
}