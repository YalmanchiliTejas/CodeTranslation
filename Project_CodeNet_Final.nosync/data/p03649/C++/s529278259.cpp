#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<ll,ll> P;

int main() {
  int n; cin>>n;
  ll a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) a[i]-=n-1;
  ll s[n]; fill(s,s+n,0);
  ll an=0;
  
  bool update=true;
  while(update) {
    update=false;
    for(int i=0;i<n;i++) {
      a[i] += an-s[i]; s[i]=an;
    }
    //cout<<"upp:"<<endl;
    //for(ll x:a) cout<<x<<" "; cout<<endl;
    //for(ll x:s) cout<<an-x<<" "; cout<<endl;
    for(int i=0;i<n;i++) {
      if (a[i] > 0) {
        update=true;
        ll gt = a[i] / n;
        a[i] -= gt * n;
        if (a[i] > 0) gt++, a[i]-=n;
        an += gt;
        s[i] += gt;
      }
    }
    //cout<<an<<": ";
    //for(ll x:a) cout<<x<<" "; cout<<endl;
    //for(ll x:s) cout<<x<<" "; cout<<endl;
  }
  cout<<an<<endl;
}