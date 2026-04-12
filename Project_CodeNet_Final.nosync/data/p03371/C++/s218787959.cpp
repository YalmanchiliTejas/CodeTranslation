#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
 
typedef long long ll;

#define rep(i,n) for(ll i = 0; i < n; i++)
 
using namespace std;
 
const ll INF = ll(1e18)+1;
const double PI=3.14159265358979323846;

int main(){
  ll a,b,c,x,y,ans=INF;
  cin >> a >> b >> c >> x >> y;
  for(ll abn=0; abn<=2*(max(x,y)); abn++){
    if(abn%2==1) continue;
    ll an = max(x-abn/2,ll(0));
    ll bn = max(y-abn/2,ll(0));
    ans = min(ans, an*a+bn*b+abn*c);
  }
  cout << ans << endl;
}
