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
  int N, M;
  while(cin >>N >>M && (N || M)){
    vector<int> v(N + M + 1);
    REP(i, N) cin >>v[i];
    REP(i, M) cin >>v[i + N];
    v[N + M] = 0;
    SORT(v);
    int ans = 0;
    FOR(i, 1, N + M + 1) ans = max(ans, v[i] - v[i - 1]);
    cout <<ans <<endl;
  }
  return 0;
}