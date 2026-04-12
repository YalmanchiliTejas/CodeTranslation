#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  if(k == 0){
    ans -= n;
  }
  for(int i = k + 1; i <= n; i++) {
    ll r = n % i;
    ll p = (n - r) / i;
    ans += p * max(0, i - k);
    ans += max((ll)0, r - k + 1);
  }
  
  cout << ans << endl;
  return 0;
}