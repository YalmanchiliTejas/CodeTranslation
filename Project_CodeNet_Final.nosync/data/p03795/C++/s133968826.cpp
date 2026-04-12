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
  int n;
  cin >> n;
  cout << n * 800 - n / 15 * 200 << endl;
  return 0;
}