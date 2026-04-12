#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  int n;cin >>n;
  vector<ll> v(n);
  ll tot = 0;
  for(int i=0;i<n;++i){
    ll t ;cin>>t;
    v[i]=t;
    tot += t;
    tot = tot%mod;
  }
  ll out =0;
  for(int i=0;i<n-1;++i){
    tot -= v[i];
    if(tot<0) tot += mod;
    out += (v[i]*tot)%mod;
    out = out%mod;
  }
  cout << out << endl;
  return 0;
}
