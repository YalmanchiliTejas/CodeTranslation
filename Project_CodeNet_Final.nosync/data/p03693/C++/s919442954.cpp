#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <array>
#include <float.h>
#include <memory>
#include <functional>
#include <iomanip>
#include <queue>
#include <random>
#include <map>
#include <set>

#pragma warning(disable:4996)

using namespace std;

int main() {
  int v = 0;
  for (int i = 0; i < 3; ++i) {
    int vv;
    cin >> vv;
    v += vv*pow(10, 2 - i);
  }
  cout << (v % 4 == 0 ? "YES" : "NO") << endl;
  return 0;
}
