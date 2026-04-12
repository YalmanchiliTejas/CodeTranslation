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

class C{
  public:
    string s;
    int i, a, b, c;
    C(){}
    C(string _s, int _i, int _a, int _b, int _c) { s = _s; i = _i; a = _a; b = _b; c = _c; }
    bool operator < (const C &_) const {
      int x = a * 3 + c, y = _.a * 3 + _.c;
      return (x != y ? x > y : i < _.i);
    }
};

int main() {
  int N;
  bool f = false;
  while(cin >>N && N){
    if(f) cout <<endl;
    f = true;
    vector<C> v(N);
    REP(i, N){
      cin >>v[i].s >>v[i].a >>v[i].b >>v[i].c;
      v[i].i = i;
    }
    SORT(v);
    REP(i, N) cout <<v[i].s <<"," <<v[i].a * 3 + v[i].c <<endl;
  }


  return 0;
}