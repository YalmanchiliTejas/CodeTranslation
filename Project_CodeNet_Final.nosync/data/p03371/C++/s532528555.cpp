#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main(void){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 1000000007;
  rep(i,100001) {
    ll cost = 2 * c * i + max(x-i,0) * a + max(y-i,0) * b;
    ans = min(ans,cost);
  }
  cout << ans << endl;
}
