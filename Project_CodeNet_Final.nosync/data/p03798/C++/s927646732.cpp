#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define INF 1100000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define Decimal fixed << setpresicion(20)
#define SHOWP(x) cerr<<"("<<(x).FI<<", "<<(x).SE<<")"<<endl;
#define SHOWX(x) cerr<<#x<<": "<<x<<endl;
#define SHOWVEC(v, e) REP(i, e) cerr << (v[i]) << ' '; cerr << endl;
#define SHOW2D(a, h, w) REP(i, h){REP(j, w)cerr<<setw(3)<<(a[i][j])<<' ';cerr<<endl;}

typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
  int N; cin >> N;
  string S; cin >> S;

  string pat[4];
  if (S[0] == 'o') {
    pat[0] = "SSS";
    pat[1] = "SWW";
    pat[2] = "WWS";
    pat[3] = "WSW";
  } else {
    pat[0] = "SWS";
    pat[1] = "SSW";
    pat[2] = "WSS";
    pat[3] = "WWW";
  }

  string ans(N, '!');
  REP(i, 4) {
    ans[0] = pat[i][0];
    ans[1] = pat[i][1];
    for (int j = 1; j < N - 1; j++) {
      if (ans[j] == 'S') {
        if (S[j] == 'o') ans[j + 1] = ans[j - 1];
        else ans[j + 1] = (ans[j - 1] == 'S' ? 'W' : 'S');
      } else {
        if (S[j] == 'x') ans[j + 1] = ans[j - 1];
        else ans[j + 1] = (ans[j - 1] == 'S' ? 'W' : 'S');
      }
    }
    if (ans[N - 1] == pat[i][2]) {
      if (S[N - 1] == 'o') {
        if (ans[N - 1] == 'S' && ans[N - 2] != ans[0]) continue;
        else if (ans[N - 1] == 'W' && ans[N - 2] == ans[0]) continue;
      }
      if (S[N - 1] == 'x') {
        if (ans[N - 1] == 'W' && ans[N - 2] != ans[0]) continue;
        else if (ans[N - 1] == 'S' && ans[N - 2] == ans[0]) continue;
      }
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}