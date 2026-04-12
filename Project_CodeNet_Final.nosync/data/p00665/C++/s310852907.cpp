#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

// Cð½·àÌªlb¤É èACð½·ÅålðßéÆ«BCð½·àÌª³¢Æ«ÌÉÓB
template<class T> T upper_search(T lb, T ub, bool (*C)(T)) {
  while(ub-lb>1) { // ±±ÍKÉB
    T mid = (lb+ub)/2;
    if (C(mid)) lb = mid;       // Å¬lðßéÈçlbÆubðüêÖ¦é
    else ub = mid;
  }
  return lb;
}

struct P {
  string name;
  int x;
  P(char *name, int x) : name(name), x(x) {}
  P() {}
};
bool operator<(const P &a, const P &b) {
  return a.x != b.x ? a.x > b.x : a.name < b.name;
}

int x[100000];
P fav[100000];
P v[100000];

int n, m, k, l;

bool C(int a) {
  if (a > k) return 0;
  P standard ;
  int c = 0;
  REP(i, n) {
    if (fav[c].name == v[i].name) c++;
    if (i == k-a+c) {
      standard = v[i];
      break;
    }
  }
  if (standard.name == "") return 1;
  // cout << "a = " << a << endl;
  // cout << standard.name << " " << standard.x << endl;
  int need = 0;
  REP(i, a) {
    if (standard < fav[i] ) {   // standardÌÙ¤ªÊªã
      if (standard.name < fav[i].name) { // standardª«Å¢
        need += standard.x - fav[i].x + 1;
      } else {
        need += standard.x - fav[i].x;
      }
    }
    if (need > l) return 0;
  }
  // cout << "need = " << need << endl;
  return 1;
}

int main() {
  while(scanf("%d%d%d%d",&n,&m,&k,&l), n) {
    map<string, int> id;
    REP(i, n) {
      char tmp[20];
      scanf("%s %d", tmp, x+i);
      id[string(tmp)] = i;
      v[i] = P(tmp, x[i]);
    }
    REP(i, m) {
      char tmp[20];
      scanf("%s", tmp);
      fav[i] = P(tmp, x[id[string(tmp)]]);
    }
    sort(v, v+n);
    sort(fav, fav+m);
    // REP(i,n) {
    //   cout << v[i].name << " " << v[i].x << endl;
    // }
    // cout << endl;
    // REP(i,m) {
    //   cout << fav[i].name << " " << fav[i].x << endl;
    // }
    cout<<upper_search<int>(0, m+1, C)<<endl;
  }
}