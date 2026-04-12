#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  
  vector<int> sorted = A;
  sort(sorted.begin(), sorted.end());
  int left = sorted[N / 2 - 1];
  int right = sorted[N / 2];
  
  for (int a : A) {
    if (a <= left) {
      cout << right << '\n';
    } else {
      cout << left << '\n';
    }
  }
  
  return 0;
}
