#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <complex>
#include <numeric>
#include <list>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  list<int> b;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) {
    if(i % 2) {
      b.push_back(a[i]);
    } else {
      b.push_front(a[i]);
    }
  }
  if(n % 2) {
    FOR(e, b) {
      if(e != b.begin()) cout << " ";
      cout << (*e);
    }
  } else {
    RFOR(e, b){
      if(e != b.rbegin()) cout << " ";
      cout << (*e);
    }
  }
  cout << endl;
}
