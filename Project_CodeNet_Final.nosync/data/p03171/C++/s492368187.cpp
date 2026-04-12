#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n),psum(n+1);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    psum[i+1] = psum[i]+a[i];
  }
  vector<vector<ll>> first(n,vector<ll>(n));
  for(int i = 0; i < n; ++i) first[i][i] = a[i];
  for(int l = 1; l < n; ++l){
    for(int i = 0; i+l < n; ++i){
      ll val1 = a[i] + (psum[i+l+1]-psum[i+1]-first[i+1][i+l]);
      ll val2 = a[i+l] + (psum[i+l]-psum[i]-first[i][i+l-1]);
      first[i][i+l] = max(val1,val2);
    }
  }
  cout << 2*first[0][n-1] - psum[n];
  return 0;
}