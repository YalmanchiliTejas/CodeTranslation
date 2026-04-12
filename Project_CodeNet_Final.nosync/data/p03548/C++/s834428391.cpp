#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cassert>
#include <memory>
#include <stack>
#include <set>
#include <map>

#define MAX_SIZE 100000000
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  int x,y,z; cin >> x >> y >> z;
  int remain_x = x - z;
  int ans = remain_x / (y + z);
  cout << ans << endl;
}
