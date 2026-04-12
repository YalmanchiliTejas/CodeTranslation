#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main(void){
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> psum = vector<ll>(), sum = vector<ll>();
  psum.push_back(1);
  sum.push_back(1);
  for(int i = 1; i <= n; ++i){
    psum.push_back(psum[i-1]*2+1);
    sum.push_back(sum[i-1]*2+3);
  }
  ll ans = 0;
  for(int i = n; i >= 0; --i){
    if (i == 0){
      ++ans;
      break;
    }
    if (x == 1){
      break;
    }
    if (x == sum[i]){
      ans += psum[i];
      break;
    }
    if (x*2-1 == sum[i]){
      ans += psum[i-1]+1;
      break;
    }
    if (x <= sum[i]/2){
      --x;
    }else{
      ans += psum[i-1]+1;
      x -= sum[i-1]+2;
    }
  }
  cout << ans << endl;
  return 0;
}
