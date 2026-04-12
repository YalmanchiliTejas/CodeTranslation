#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  int a, b, c, x, y, ans = 0;
  cin >> a >> b >> c >> x >> y;

  if(x>y){
    swap(x,y);
    swap(a,b);
  }

  if(a+b>=c*2){
    ans += x * c * 2;
    y -= x;
    x = 0;
  }

  if(b>c*2){
    ans += y * c * 2;
    y = 0; 
  }

  ans += x * a;
  ans += y * b;

  cout << ans;

  return 0;
}
