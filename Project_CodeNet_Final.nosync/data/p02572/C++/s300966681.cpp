#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e9+7;



void solve(){
  ll n;
  cin>>n;
  vector<ll>v(n);
  for(ll i=0;i<n;i++){
    cin>>v[i];
  }
  vector<ll>prefix(n, 0);
  prefix[n-1] = v[n-1];
  for(ll i=n-2; i>=0;i--){
    prefix[i] = prefix[i+1]+v[i];
    prefix[i] %= N;
  }
  ll ans = 0;
  for(ll i=0;i<n-1;i++){
    ans += (v[i]*prefix[i+1])%N;
    ans %= N;
  }
  cout<<ans;
}
int main(){
  // freopen("input.txt", "r",stdin);
  // freopen("output.txt", "w", stdout);
  ll t;
  // cin>>t;
  t = 1;
  while(t--){
    solve();
  }
}
























/*
  1 2 3 4 5 6 7 8

  6 7 8 1 2 3 4 5


*/
