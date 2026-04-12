#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
using ll = long long;

#define right true
#define left false

int main()
{
  map<char, bool> a;
  a['q'] = right;
  a['w'] = right;
  a['e'] = right;
  a['r'] = right;
  a['t'] = right;
  a['a'] = right;
  a['s'] = right;
  a['d'] = right;
  a['f'] = right;
  a['g'] = right;
  a['z'] = right;
  a['x'] = right;
  a['c'] = right;
  a['v'] = right;
  a['b'] = right;
  a['y'] = left;
  a['u'] = left;
  a['i'] = left;
  a['o'] = left;
  a['p'] = left;
  a['h'] = left;
  a['j'] = left;
  a['k'] = left;
  a['l'] = left;
  a['n'] = left;
  a['m'] = left;
  string s;
  while (cin >> s, s != "#")
  {
    bool pre = a[s[0]];
    int sum = 0;
    for (int i = 1; i < s.size(); ++i)
    {
      if (pre != a[s[i]])
      {
        sum++;
      }
      pre = a[s[i]];
    }
    cout << sum << endl;
  }

  return 0;
}
