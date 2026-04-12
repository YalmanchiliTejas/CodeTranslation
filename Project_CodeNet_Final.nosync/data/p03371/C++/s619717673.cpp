#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long ans = 1ll<<60;
  for(int i = 0; i <= x; i++){
  	long long now = i * a;
    now += 2 * (x - i) * c;
    long long canC = min((x - i), y);
    now += (y - canC) * b;
    ans = min(ans, now);
  }
  for(int i = 0; i <= y; i++){
  	long long now = i * b;
    now += 2 * (y - i) * c;
    long long canC = min((y - i), x);
    now += (x - canC) * a;
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
