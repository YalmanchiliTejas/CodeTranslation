#include <algorithm>
#include <bitset>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, h;
  int maxh = 0;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> h;
    if (maxh <= h) {
      count++;
    }
    maxh = max(h, maxh);
  }
  cout << count;
}
