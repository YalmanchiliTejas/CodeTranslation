#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  string l = "qwertasdfgzxcvb", r = "yuiophjklnm", s;
  while (cin >> s && s != "#") {
    string condi = (l.find(s[0]) != string::npos) ? l : r;
    int count = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (condi.find(s[i]) == string::npos) {
        count++;
        condi = (l.find(s[i]) != string::npos) ? l : r;
      }
    }
    cout << count << endl;
  }
  return 0;
}

