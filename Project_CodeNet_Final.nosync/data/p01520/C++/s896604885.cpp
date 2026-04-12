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
  int N, T, E; cin >>N >>T >>E;
  int ans = -1;
  REP(i, N){
    int x; cin >>x;
    int _x = x;
    while(T + E >= _x){
      if(T - E <= _x && T + E >= _x) ans = i + 1;
      _x += x;
    }
  }
  cout <<ans <<endl;
  return 0;
}