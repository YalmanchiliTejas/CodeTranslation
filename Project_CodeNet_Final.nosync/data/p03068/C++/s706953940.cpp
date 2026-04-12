#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{

  int n;
  string s;
  int k;
  cin >> n;
  cin >> s;
  cin >> k;

  char c = s[k - 1];

  for(int i = 0;
      i < n;
      ++i)
    {
      if(s[i] != c)
        {
          s[i] = '*';
        }
    }

  cout << s << endl;

  return 0;
}
