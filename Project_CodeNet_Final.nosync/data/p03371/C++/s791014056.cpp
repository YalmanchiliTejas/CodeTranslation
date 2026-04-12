#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll sum = 0;
  if(a+b>=c*2){
    sum += c*2*min(x,y);
    if(max(x,y) == x){
      sum += min(c*2,a)*abs(x-y);
    }
    else{
      sum += min(c*2,b)*abs(x-y);
    }
  }
  else{
    sum += a*x + b*y;
  }
  cout << sum << endl;
}
    