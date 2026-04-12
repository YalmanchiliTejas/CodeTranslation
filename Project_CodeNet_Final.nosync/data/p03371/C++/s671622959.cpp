#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >>y;
  int ans = max(x, y) * 2 * c;
  if(a+b>c*2){
    ans = min(ans, c*2*min(x, y)+a*(x-min(x,y))+b*(y-min(x,y)));
  }else{
    ans = min(ans, a*x+b*y);
  }
  cout << ans << endl;
  return 0;
}
