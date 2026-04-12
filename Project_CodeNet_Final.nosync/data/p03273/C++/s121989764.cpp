#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define CONCAT(x,y) (x).insert((x).end(),(y).begin(),(y).end())
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define AND(x,y,z) set_intersection((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define FOR(i,a,b) for (int i=(int)(a);i<(int)(b);++i)
#define FORE(i,a,b) for (int i=(int)(a);i<=(int)(b);++i)
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FOR(i,0,n)

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> VEC;

int main() {
  int H,W;cin>>H>>W;
  char grid[H][W];
  bool w_checker[W];
  bool h_checker[H];
  REP(i,H)REP(j,W) {
    char a;cin>>a;
    grid[i][j] = a;
  }
  REP(i,H) h_checker[i] = false;
  REP(j,W) w_checker[j] = false;
  REP(i,H)REP(j,W) {
    if (grid[i][j] == '#') {
      w_checker[j] = true;
      h_checker[i] = true;
    }
  }
  REP(i,H) {
    if (!h_checker[i]) continue;
    REP(j,W) {
      if (!w_checker[j]) continue;
      cout << grid[i][j];
    }
    cout << endl;
  }

  return 0;
}
