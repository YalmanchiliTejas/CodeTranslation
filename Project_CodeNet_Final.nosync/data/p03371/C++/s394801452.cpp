#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b,c,x,y,ans;
  cin >> a >> b >> c >> x >> y;
  if(y>x) {
    swap(x,y);
    swap(a,b);
  }
  ans=y*min(a+b,c*2);
  ans+=(x-y)*min(a,c*2);
  cout << ans << endl;
}