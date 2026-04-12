#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#define MP make_pair
using ll = long long;
using namespace std;

int main()
{
  int x,y,z;
  cin >> x >> y >> z;
  int ans = 0;
  int h = 0;
  for(;;){
    h += z;
    if(h + y + z > x)
      break;
    h += y;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
