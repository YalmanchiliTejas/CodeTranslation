#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int main(){
  ll n, A[200100], tmp = 0, ans = 0;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> A[i];
  for(int i=n-2; i>=0; --i){
      tmp += A[i+1];
      tmp = tmp%MOD;
      ans += A[i]*tmp%MOD;
      ans = ans%MOD;
  } 
  cout << ans << endl;
}