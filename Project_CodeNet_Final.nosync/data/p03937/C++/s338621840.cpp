#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <bitset>
#include <iostream> 
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <initializer_list>
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <regex>

using namespace std;

int main(int argc, char *argv[])
{  
  int H, W;
  cin >> H >> W;
  int sum = 0;
  for (int i = 0; i < H; ++i) 
    {
      for (int j = 0; j < W; ++j)
        {
          char c;
          cin >> c;
          if (c == '#') ++sum;
        }
    }
  if (sum == H + W - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
