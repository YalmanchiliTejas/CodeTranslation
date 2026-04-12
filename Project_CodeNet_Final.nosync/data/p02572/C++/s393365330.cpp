#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

int main(void){
  ll n;
  cin >> n;
  vector<ll> A(n);
  ll sum = 0;
  for (int i=0; i<n; i++){
    cin >> A[i];
    sum += A[i];
    sum %= mod;
  }
  ll ans = 0;
  for (int i=0; i<n; i++){
    sum -= A[i];
    if (sum < 0) sum+=mod;

    ans+=A[i]*sum;
    ans%=mod;
  }

  cout << ans << endl;
}