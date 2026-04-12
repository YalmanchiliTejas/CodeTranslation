#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(ll i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  ll n;
  cin >> n;
  if(n % 2 == 0){
    vector<ll> a(n/2);
    vector<ll> b(n/2);
    rep(i,n){
      if(i % 2 == 0) cin >> a[i/2];
      else cin >> b[i/2];
    }
    reverse(b.begin(),b.end());
    rep(i,n/2){
      cout << b[i] << " ";
    }
    rep(i,n/2){
      cout << a[i] << " ";
    }
    cout << endl;
  }
  else{
    vector<ll> a((n+1)/2);
    vector<ll> b(n/2);
    rep(i,n){
      if(i % 2 == 0) cin >> a[i/2];
      else cin >> b[i/2];
    }
    reverse(a.begin(),a.end());
    rep(i,(n+1)/2){
      cout << a[i] << " ";
    }
    rep(i,n/2){
      cout << b[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
