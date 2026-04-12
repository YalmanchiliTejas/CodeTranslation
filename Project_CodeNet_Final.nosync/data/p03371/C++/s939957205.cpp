#include <iostream>
using namespace std;
using ll = long long;
int main(void){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ab = c * 2;

  ll ans = 1<<30;
  int z = max(x,y);
  for(int abi=0;abi<=z;abi++){
    int ac = x>abi ? x-abi:0;
    int bc = y>abi ? y-abi:0;
    ans = min(ans,(ll)(a*ac+b*bc+ab*abi));
  }

  cout << ans << endl;
}
