#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;

  int t = x / (y+z);
  if(x-t*(y+z) < z) cout << t-1 << endl;
  else cout << t << endl;
  return 0;
}
