#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if((a * 100 + b * 10 + c) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}