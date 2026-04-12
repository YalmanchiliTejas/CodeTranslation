#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void) {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  int ans;
  if(a>=2*c && b>=2*c){
    ans = max(x,y) * 2 * c;
  } else if(a>=2*c) {
    ans = x*2*c + max(0, y-x) * b;
  } else if(b>=2*c) {
    ans = y*2*c + max(0, x-y) * a;
  } else if(a+b <= 2*c) {
    ans = a*x+b*y;
  } else if(x>y) {
    ans = y*2*c + a*(x-y);
  } else {
    ans = x*2*c + b*(y-x);
  }

  cout << ans << endl;  
  return 0;
}
