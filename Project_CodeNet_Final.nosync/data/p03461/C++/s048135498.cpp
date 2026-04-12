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
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

int main(void){
  int n = 100;
  int a, b;
  int f = 1;
  cin >> a >> b;
  vector<vi> d(a, vi(b));
  vector<vi> finished(a, vi(b, 0));
  REP(i, a) REP(j, b) cin >> d[i][j];
  vector<vector<pii> > g(2 * n + 2);
  REP(i, n + 1) {
    REP(j, n + 1) {
      int min_cost = 0;
      REP(k, a) {
        REP(l, b) {
          int x = (k + 1) * i + (l + 1) * j;
          int y = x - d[k][l];
          if(y < 0) min_cost = max(min_cost, -y);
        }
      }
      g[i+10].push_back(pii(220 - j, min_cost));
      REP(k, a) {
        REP(l, b){
          if((k + 1) * i + (l + 1) * j + min_cost == d[k][l]) finished[k][l] = 1;
        }
      }
    }
  }
  REP(i, a) REP(j, b) if(!finished[i][j]) f = 0;

  if(!f) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  int m = 2 * n + 2;
  REP(i, g.size()) m += g[i].size();
  cout << "300 " << m << endl;
  cout << "1 10 0" << endl;
  cout << "220 2 0" << endl;
  REP(i, 100) {
    cout << i + 10 << " " << i + 11 << " X" << endl;
    cout << i + 120 << " " << i + 121 << " Y" << endl;
  }
  REP(i, g.size()) {
    REP(j, g[i].size()) {
      cout << i << " " << g[i][j].first << " " << g[i][j].second << endl;
    }
  }
  cout << "1 2" << endl;
}
