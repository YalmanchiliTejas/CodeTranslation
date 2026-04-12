#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if(a+b<=2*c) cout << a*x+b*y << endl;
  else{
    if(x<=y) cout << min(2*c*x+b*(y-x), 2*c*y) << endl;
    //if(x<=y){
    else cout << min(2*c*y+a*(x-y), 2*c*x) << endl;
  }
}