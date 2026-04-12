#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAXR 100000

int main()
{
  int h, w; cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  REP(i, h) {
    REP(j, w) {
      cin >> a.at(i).at(j);
    }
  }

  REP(i, h) {
    int cnt_w = 0;
    REP(j, w) {
      if (a.at(i).at(j) == '.') cnt_w++;
    }
    if (cnt_w == w) REP(j, w) a.at(i).at(j) = '0';
  }

  REP(j, w) {
    int cnt_h = 0;
    REP(i, h) {
      if (a.at(i).at(j) == '.' || a.at(i).at(j) == '0') cnt_h++;
    }
    if (cnt_h == h) REP(i, h) a.at(i).at(j) = '0';
  }

  REP(i, h) {
    stringstream ss;
    REP(j, w) {
      char elem = a.at(i).at(j);
      if (elem != '0') ss << elem;
    }
    if (ss.str().size() != 0) cout << ss.str() << endl;
  }
  return 0;
}
