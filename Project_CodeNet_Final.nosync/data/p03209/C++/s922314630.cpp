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
  ll N, X;
  scanf("%lld %lld", &N, &X);

  ll n_patty[N+1];
  ll n_all[N+1];
  n_patty[0] = 1;
  n_all[0] = 1;
  rep(i, N) n_patty[i+1] = n_patty[i] * 2 + 1;
  rep(i, N) n_all[i+1] = n_all[i] * 2 + 3;

  ll ans = 0;
  ll ptr = X;
  rrep(l, N+1){
    if(l == 0){
      ans++;
      break;
    }
    if(ptr == (n_all[l-1] + 2)){
      ans += n_patty[l-1] + 1;
      break;
    }
    else if(ptr == n_all[l]){
      ans += n_patty[l];
      break;
    }
    else if(ptr < (n_all[l-1] + 2)){
      ptr--;
      if(ptr < 1) break;
    }
    else{
      ans += n_patty[l-1] + 1;
      ptr -= n_all[l-1] + 2;
    }
  }
  cout << ans << endl;
  return 0;
}
