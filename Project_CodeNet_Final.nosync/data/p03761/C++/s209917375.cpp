#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> s_list;
  s_list.reserve(n);
  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    s_list.emplace_back(move(tmp));
  }

  vector<int> min_count_array(26, 50);
  for (int i = 0; i < n; ++i) {
    const string &s = s_list[i];
    vector<int> count(26, 0);
    for (string::const_iterator it = s.begin(); it != s.end(); ++it) {
      ++(count[*it - 'a']);
    }

    for (int j = 0; j < 26; ++j) {
      min_count_array[j] = min(min_count_array[j], count[j]);
    }
  }

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < min_count_array[i]; ++j) {
      cout << static_cast<char>(i + 'a');
    }
  }
  cout << endl;

  return 0;
}
