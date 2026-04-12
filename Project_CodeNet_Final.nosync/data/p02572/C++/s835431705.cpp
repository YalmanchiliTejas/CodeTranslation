#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;
 
 
int main(){
  int n;
  cin >> n;
  vector<ll> a(n, 0);
  rep(i, n)cin>>a[i];
  vector<ll> c_sum(n+1, 0);
  rep(i, n){
      c_sum[i+1]=(c_sum[i]+a[i])%(1000000007);
  }
  
  ll ans = 0;
  rep(i, n){
     ll sum = (c_sum[n]-c_sum[i+1]);
     if(sum<0)sum+=1000000007;
     
     ans += sum*a[i];
     ans = ans%(1000000007);
 } 
 
 
 cout << ans << endl;
}