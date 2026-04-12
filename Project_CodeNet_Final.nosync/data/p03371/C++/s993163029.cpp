#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  ll a,b,c,X,Y;
  cin >> a >> b >> c >> X >> Y;
  ll min=X*a+Y*b;
  for(ll i=1;i<=max(X,Y);i++) {
    ll xq=X,yq=Y,ans;
    ans = ((c*2)*i) + (X-i)*a+(Y-i)*b;
    if(X-i<=0) {
      ans = ((c*2)*i)+(Y-i)*b;
    }
    if(Y-i<=0) {
      ans = ((c*2)*i)+(X-i)*a;
    }
    if(max(X,Y)-i==0) {
      ans = ((c*2)*i);
    }
    if(min>ans) min=ans;
  }
  cout << min << endl;
}