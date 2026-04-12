#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;

int main() {
  map<char, int> m;
  m['q'] = 0; m['w'] = 0; m['e'] = 0; m['r'] = 0; m['t'] = 0;
  m['a'] = 0; m['s'] = 0; m['d'] = 0; m['f'] = 0; m['g'] = 0;
  m['z'] = 0; m['x'] = 0; m['c'] = 0; m['v'] = 0; m['b'] = 0;
  m['y'] = 1; m['u'] = 1; m['i'] = 1; m['o'] = 1; m['p'] = 1;
  m['h'] = 1; m['j'] = 1; m['k'] = 1; m['l'] = 1;
  m['n'] = 1; m['m'] = 1;
  string s;
  while(cin >>s && s != "#"){
    int t = m[s[0]], ans = 0;
    FOR(i, 1, s.length()){
      if(t != m[s[i]]) ++ans;
      t = m[s[i]];
    }
    cout <<ans <<endl;
  }
  return 0;
}