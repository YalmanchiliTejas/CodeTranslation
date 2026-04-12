#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  int a,b,c,x,y;
  int ans = 500000005;
  int minans = 500000005;

  cin >> a >> b >> c >> x >> y;

  ans = a*x + b*y;
  minans = ans;
  int mx = min(x, y);

  //
  for(int i = 0; i <= mx; i++) {
    int aa = i * a;
    int bb = i * b;
    if(mx > x){
      aa = x * a;
    }
    if(mx > y){
      bb = y * b;
    }
    ans = a*x + b*y;
    ans = ans - aa - bb + c*2*i;
    minans = min(ans, minans);
  }
  //cだけで良い場合
  ans = max(x, y)*c*2;
  minans = min(ans, minans);

  cout << minans << endl;
}
