#include <bits/stdc++.h>

#define INF 1e9
#define LLINF 1e18
#define PI 3.1415926535897932384
#define MOD 1000000007

#define REP(i, n) for(int i=0; i<n; ++i)
#define REPR(i, n) for(int i=n; i>=0; --i)
#define REPS(i, m, n) for(int i=m; i<n; ++i)
#define SORT(v, n) sort(v, v+n)
#define RSORT(v, n) sort(v, v+n, greater<int>());
#define VSORT(v) sort(v.begin(), v.end());
#define PB(n) push_back(n)
using namespace std;

int main() {
  int n;
  vector<int> v;
  REP(i, 12) {
    cin >> n;
    v.PB(n);
  }
  int cnt = 0;
  VSORT(v);
  REPS(i, 0, 11) {
    if(v[i] != v[i+1]) {
      ++cnt;
      if(((i == 3) && (i+1 == 4)) || ((i == 7) && (i+1 == 8))) {
        continue;
      } else {
        cout << "no" << endl;
        return 0;
      }
    }
  }
  if(cnt == 0 || cnt == 1 || cnt == 2) cout << "yes" << endl;

}




