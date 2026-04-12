#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <math.h>

using namespace std;

int main()
{
  string s;
  cin >> s;

  set<char> sets;
  for (int i = 0; i < 3; ++i)
  {
    sets.insert(s[i]);
  }

  if (sets.size() == 1) cout << "No" << endl;
  else cout << "Yes" << endl;
}