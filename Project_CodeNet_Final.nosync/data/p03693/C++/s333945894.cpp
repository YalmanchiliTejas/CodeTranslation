//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
int main(int argc, char *argv[])
{
  int r, g, b;

  cin >> r >> g >> b;

  if((100*r+g*10+b)%4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
