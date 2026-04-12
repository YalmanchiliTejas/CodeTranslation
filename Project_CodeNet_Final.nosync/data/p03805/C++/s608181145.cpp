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
#include <random>
#include <map>
#include <set>
#include <boost/lexical_cast.hpp>

using namespace std;


using ULL = decltype(0ull);
constexpr auto DIV = 1000000007ull;
constexpr auto MAX = numeric_limits<ULL>::max();

struct Node {
  vector<int> next;
};

int N, M;

int Calc(const vector<Node>& Root, int Index, vector<bool>& Map) {
  int result = 0;
  Map[Index] = true;
  if (all_of(Map.begin(), Map.end(), [](const auto& v) {return v; })) {
    result = 1;
  }
  for (auto&& next : Root[Index].next) {
    if (!Map[next]) {
      result += Calc(Root, next, Map);
    }
  }
  Map[Index] = false;
  return result;
}

int Calc(const vector<Node>& Root) {
  int result;
  vector<bool> map(N, false);
  return Calc(Root, 0, map);
}

int main() {
  cin >> N >> M;
  vector<Node> node(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    node[a - 1].next.push_back(b - 1);
    node[b - 1].next.push_back(a - 1);
  }
  cout << Calc(node) << endl;
  return 0;
}
