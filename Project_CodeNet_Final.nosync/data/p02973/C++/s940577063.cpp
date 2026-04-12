#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define sz(x) int (x.size());
using namespace std;
const int MOD=1000000007;

int main(){
  int n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  deque <ll> d;
  rep(i,n){
    ll now=lower_bound(d.begin(),d.end(),a[i])-d.begin();
    if (now==0)d.push_front(a[i]);
    else d[now-1]=a[i];
  }
  cout<<d.size();
}
