#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
constexpr int64_t MOD = 1e9 + 7;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  string S;
  cin >> S;
  if (S == "AAA" || S == "BBB") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}

