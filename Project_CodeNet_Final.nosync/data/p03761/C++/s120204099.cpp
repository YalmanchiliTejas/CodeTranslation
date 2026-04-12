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
  ll n;cin>>n;
  string s,ans;
  lvector v_(n,0);
  vector<lvector> v(26,v_);
  rep(i,n) {
    cin>>s;
    ll l=s.length();
    rep(j,l) v[s[j]-'a'][i]+=1;
  }
  char c='a';
  rep(i,26) {
    lvector x=v[i];
    ll num=*min_element(x.begin(),x.end());
    rep(j,num) ans+=c;
    c++;
  }
  print(ans);
  return 0;
}