#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define INF 1100000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
  int H, W; cin >> H >> W;
  vector<string> S(H);
  REP(i, H) cin >> S[i];

  string dot = "";
  REP(j, W) dot += '.';

  vector<string> tS;
  REP(i, H) if (S[i] != dot) tS.PB(S[i]);

  vector<bool> f(W, false);
  REP(i, W) {
    REP(j, tS.size()) {
      if (tS[j][i] != '.') {
        f[i] = true;
        break;
      }
    }
  }
  REP(i, tS.size()) {
    REP(j, W) {
      if (f[j] == true) {
        cout << tS[i][j] << flush;
      }
    }
    cout << endl;
  }

	return 0;
}

