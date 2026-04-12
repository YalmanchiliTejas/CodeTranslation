#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  int x, y;
  int an=0, bn=0, cn=0;
  int ans;

  cin >> a >> b >> c >> x >> y;

  if(a+b<=2*c) {an=x;bn=y;cn=0;}
  else if(a+b>2*c){
    if(x>=y) {
      if(2*c<=a) {cn=2*x;}
      else if(2*c>a) {an=x-y;cn=2*y;}
    }
    else if(x<y) {
      if(2*c<=b) {cn=2*y;}
      else if(2*c>b) {bn=y-x;cn=2*x;}
    }
  }

  // cout << an <<" "<< bn <<" " << cn <<" " << endl;

  ans = a*an + b*bn + c*cn;

  cout << ans << endl;

  return 0;
}
