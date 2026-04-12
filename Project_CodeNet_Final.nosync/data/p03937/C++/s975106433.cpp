#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  int h,w;
  cin >> h >> w;
  int count = 0;
  for(int i = 1; i <= h*w; i++) {
    char c;
    cin >> c;
    if(c == '#') {
      count++;
    }
  }
  bool flag = false;
  if(count == h+w-1) {
    flag = true;
  }
  if(flag) {
    cout << "Possible" << endl;
  }else {
    cout << "Impossible" << endl;
  }
  return 0;
}