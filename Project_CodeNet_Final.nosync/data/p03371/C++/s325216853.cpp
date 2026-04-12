#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
typedef long long ll;


int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int tmp = min(x, y);
  ll ans = min(a+b, 2*c) * tmp;
  if(x > y){
    ans += min(2*c, a) * (x-y);
  }else{
    ans += min(2*c, b) * (y-x);
  }
  cout << ans << endl;
  return 0;
}

