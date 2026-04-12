#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;
typedef long long int ll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)

int main(){
  ll N;
  cin >> N;
  ll H[N];
  rep(i, N) cin >> H[i];

  ll hmax = H[0];
  ll ans = 1;
  repi(i, 1, N){
    if(H[i] >= hmax){
      hmax = H[i];
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
