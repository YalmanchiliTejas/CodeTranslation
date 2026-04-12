#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ull N, X;
  cin >> N >> X;

  vector<ull> pati(51);
  vector<ull> pan(51);

  pati[0] = 1;
  pan[0] = 0;
  for (auto i = 1; i <= 50; i++) {
    pati[i] = pati[i-1] + pati[i-1] + 1;
    pan[i] = pan[i-1] + pan[i-1] + 2;
  }

  ull level = N;
  ull res = 0;
  while (1) {
    if (level == 0) {
      res++;
      break;
    }
    ull rec_size = pati[level-1] + pan[level-1];
    ull mid = 1llu + rec_size + 1llu;
    if (X == 1) break;
    else if (X < mid) {
      X--;
    }
    else if (X == mid) {
      res += pati[level-1] + 1llu;
      break;
    }
    else if (X < (mid + rec_size + 1llu)) {
      X -= mid;
      res += pati[level-1] + 1llu;
    } else {
      res += pati[level-1] + pati[level-1] + 1llu;
      break;
    }
    level--;
  }

  cout << res << endl;

  return 0;
}
