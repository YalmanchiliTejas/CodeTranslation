#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void OutputError(std::string s) {
  cerr << "\033[93m" << s << "\033[m" << endl;
  return;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  std::vector<std::string> s;
  for (int i = 0; i < n; i++) {
    std::string m1;
    cin >> m1;
    s.push_back(m1);
  }
  std::vector<int> count('z' - 'a' + 1, 0);
  bool first = true;
  for (auto tgt_s : s) {
    if (first) {
      first = false;
      std::vector<int> temp_count('z' - 'a' + 1, 0);
      for (auto tgt_c : tgt_s) {
        temp_count[tgt_c - 'a']++;
      }
      count = temp_count;
    } else {
      std::vector<int> temp_count('z' - 'a' + 1, 0);
      for (auto tgt_c : tgt_s) {
        temp_count[tgt_c - 'a']++;
      }
      for (int i = 0; i < 'z' - 'a' + 1; i++) {
        count[i] = std::min(count[i], temp_count[i]);
      }
    }
  }
  std::string result;
  for (int i = 0; i < 'z' - 'a' + 1; i++) {
    for (int j = 0; j < count[i]; j++) {
      result += (i + 'a');
    }
  }
  cout << result << endl;

  return 0;
}
