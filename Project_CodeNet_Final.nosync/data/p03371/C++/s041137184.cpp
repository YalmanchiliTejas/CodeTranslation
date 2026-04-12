#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
const ll INF = 1e18 ;
int main() {
  int A ,B ,C ;
  cin >> A >> B >> C ;
  int X , Y ;
  cin >> X >> Y ;
  ll ans = INF ;
  ll count = A*X + B*Y ;
  rep( i , min(X,Y) ){
    ans = min(count,ans)  ;
    count += 2*C - A - B  ;
    ans = min(count,ans)  ;
    //cout << count << endl ;
  }
  rep( i , max(X,Y) - min(X,Y) ){
    if( X >= Y ) count += 2*C - A ;
    else        count  += 2*C - B ;
    ans = min(count,ans)  ;
  }
  cout << ans << endl ;
}
