#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;

int main() {
  set<char> left;
  left.insert('y');
  left.insert('h');
  left.insert('n');
  left.insert('u');
  left.insert('j');
  left.insert('m');
  left.insert('i');
  left.insert('k');
  left.insert('o');
  left.insert('l');
  left.insert('p');
  while (true) {
    string s;
    cin >> s;
    if (s == "#") break;
    int len = s.size();
    bool lr = (left.count(s[0]) == 0);
    int res = 0;
    for (int i = 1; i < len; i++) {
      if (lr != left.count(s[i]) == 0) {
	res++;
	lr = !lr;
      }
    }
    cout << res << endl;
  }
}