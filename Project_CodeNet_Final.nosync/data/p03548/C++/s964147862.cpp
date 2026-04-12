# include <bits/stdc++.h>
# define INF 1e9
using namespace std;

int main(){

  int x, y, z;
  cin >> x >> y >> z;
  int ans = 0;
  if(x >= y+2*z) ans = 1;
  int cur = y+2*z;
  while(cur + z + y <= x){
    ans++;
    cur += z+y;
  }
  cout << ans << endl;

}