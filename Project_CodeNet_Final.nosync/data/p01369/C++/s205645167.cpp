#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define el endl
#define fd fixed
#define INF INT_MAX/2-1

using namespace std;

int main() {
  string s, right = "yuiopjhklnm";
  int count;
  bool use_right;
  while (cin >> s, s != "#") {
    count = 0;
    if ((int)right.find(s[0]) >= 0) use_right = true;
    else use_right = false;
    for (int i = 1; i < s.length(); i++) {
      if (use_right && (int)right.find(s[i]) < 0) {
        use_right = false;
        count++;
      }
      else if (!use_right && (int)right.find(s[i]) >= 0) {
        use_right = true;
        count++;
      }
    }
    cout << count << el;
  }
}