#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll n,k;
  ll ans = 0;
  cin >> n >> k;
  rep(b,k+1,n+1){
    ans += (b-k)*(n/b);
    if(n%b != 0) ans += max(0LL,n%b-k+1);
  }
  if(ans >= n*n) ans = n*n;
  cout << ans << endl;
}