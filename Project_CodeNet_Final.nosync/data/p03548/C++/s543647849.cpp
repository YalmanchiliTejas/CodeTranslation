#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>
using namespace std;


int main(){
  int x, y, z;
  cin >> x >> y >> z;
  int cnt = 0;
  int res = z;
  while(true){
    res += y + z;
    if(res > x){
      cout << cnt << endl;
      break;
    }
    cnt++;
  }
}