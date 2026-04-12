#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define FOR(i, first, last) for (int i = (first); i < (last); ++i)
#define REP(i, n) FOR(i, 0, n)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) std::cerr << #x << " = " << (x) << std::endl;

inline int to_int(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string to_string(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

typedef unsigned long long ull;
typedef unsigned long ul;

int main() {
  int x,y,z;
  cin>>x>>y>>z;

  int n=0;
  int len=0;

  while(len<=x) {
    len += (y+z);
    n++;
  }
  // remove overshoot
  len -= (y+z);
  n--;

  if(x - len < z) n--;

  n = max(n, 0);
  cout << n << endl;

  return 0;
}
