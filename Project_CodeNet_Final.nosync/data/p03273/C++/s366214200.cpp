#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

vector<string> s;

int main() {
  int h, w;
  cin >> h >> w;
  string str;
  int jcount = 0;
  int count = 0;
  for (int i = 0; i < h; ++i) {
    cin >> str;
    jcount = 0;
    for (int j = 0; j != str.size(); ++j) {
      if (str.at(j) == '.') ++jcount;
    }
    if (jcount == str.size()) ++count;
    else s.push_back(str);
  }
  h -= count;

  for (int i = 0; i != s[0].size(); ++i) {
    count = 0;
    for (int j = 0; j < h; ++j) {
      if (s[j][i] == '.') ++count;
      else break;
    }
    if (count == h) {
      for (int j = 0; j < h; ++j) {
        s[j].erase(s[j].begin() + i);
      }
      --i;
    }
  }

  for (int i = 0; i < h; ++i) {
    cout << s[i] << endl;
  }
  return 0;
}
