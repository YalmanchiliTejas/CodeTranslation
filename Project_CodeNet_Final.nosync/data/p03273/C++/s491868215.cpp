#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,v) for (int i = 0; i < v.size(); i++)
#define SORT(v) sort(v.begin(), v.end())
#define MIN_ELEMENT(v) min_element(v.begin(), v.end())
#define MAX_ELEMENT(v) max_element(v.begin(), v.end())
#define COUNT(v,n) count(v.begin(), v.end(), n);
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

char a[111][111];
int b[111][111];
int bh[111], bw[111];

int main()
{
  int h, w;
  cin>>h>>w;

  REP(i,h) {
    REP(j,w) {
      cin>>a[i][j];
      b[i][j] = a[i][j] == '.' ? 0 : 1;
    }
  }

  REP(i,h) {
    REP(j,w) {
      bh[i] |= b[i][j];
    }
  }
  REP(j,w) {
    REP(i,h) {
      bw[j] |= b[i][j];
    }
  }

  /*REP(i,h) {
    REP(j,w)
        cout<<(bh[i] & bw[j]);

    cout<<endl;
  }*/

  REP(i,h) {
    REP(j,w) {
      if (bh[i] && bw[j]) {
        cout<<a[i][j];
      }
    }
    if (bh[i])
      cout<<endl;
  }

  return 0;
}
