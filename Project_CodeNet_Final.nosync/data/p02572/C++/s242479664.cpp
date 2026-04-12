#include <iostream>

using namespace std;
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ll a[n];
  ll sum[n];
  for(int i=0;i<n;i++) cin>>a[i];

  sum[n-1] = 0;
  for(int i=n-2;i>=0;--i){
    sum[i] = (sum[i+1] + a[i+1]) % 1000000007;
  }

  ll ans = 0L;
  for(int i=0; i<n;++i){
    ans = (ans + a[i] * sum[i]) % 1000000007;
  }

  cout << ans << endl;

  return 0;
}
