#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  int n;
  while (cin >> n, n) {
    vector<int> v;
    bool hazime;
    int iro = -1;
    for (int i=1; i<=n; ++i) {
      bool a;
      cin >> a;
      if (i%2) {
        if (iro != a)
          v.push_back(1);
        else {
          v[v.size()-1]++;
        }
        if (i==1) hazime = a;
      } else if (iro == a)
        v[v.size()-1]++;
      else if (v.size()==1) {
        hazime ^= 1;
        v[0]++;
      } else {
        v[v.size()-2] += v[v.size()-1] + 1;
        v.pop_back();
      }
      // FOR(it,v) {
      //   cout << *it << " ";
      // }cout <<endl;
      iro = a;
    }
    int res = 0;
//    cout << "hazime = " << hazime << endl;
    REP(i,v.size()) {
      if (!hazime && !(i%2)) {
        res += v[i];
      }
      else if (hazime && i%2)
        res += v[i];
    }
    cout << res << endl;
  }
}