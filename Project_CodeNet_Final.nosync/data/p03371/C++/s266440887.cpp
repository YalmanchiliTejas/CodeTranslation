#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int sum = a * x + b * y;
  for(int i = 0; i <= max(x, y); i++){
    int res = (a * x + b * y) - (a * min(i, x) + b * min(i, y)) + (2 * i * c);
    if(res < sum){sum = res;}
  }
  cout << sum << endl;
}