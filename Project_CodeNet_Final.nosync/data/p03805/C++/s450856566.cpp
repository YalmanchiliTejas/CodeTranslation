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
  ll n,m,a,b,from=0,to=0,ans=0;cin>>n>>m;
  lvector v(n-1,0); rep(i,n-1) v[i]=i+1;
  map<P,ll> mp;
  rep(i,m) {
    cin>>a>>b;
    a--,b--;
    mp[P(a,b)]=1,mp[P(b,a)]=1;
  }
  bool isok=true;
  do{
    from=0;
    isok=true;
    for(ll i:v) {
      to=i;
      if(mp[P(from,to)]==1) from=i;
      else {isok=false;break;}
    }
    if(isok) ans++;
  }
  while(next_permutation(v.begin(),v.end()));
  print(ans);
  return 0;
}