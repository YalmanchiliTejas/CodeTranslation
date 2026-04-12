#include <bits/stdc++.h>
using namespace std;
/* {{{ */
/*-------------------------------*/
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (b) - 1; i >= (a); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define rep(i, n) for(int i = 0; i < (n); i++)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)

#define all(i) (i).begin(),(i).end()
#define rall(i) (i).begin(),(i).end(),greater<int>()
#define PB push_back
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
//#define int long long

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> llv;
typedef vector<pint> vpint;

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1}; 

inline int in(){int x;std::cin>>x;return x;}

struct FAST {FAST(){cin.tie(0);ios::sync_with_stdio(false);}} Fast;

template <class X> void print(X hoge){ cout << hoge << '\n'; }
/*-------------------------------*/
/* }}} */ 

signed main(void)
{
  char c;
  char list[5] = {'a', 'i', 'u', 'e', 'o'};

  cin >> c;

  rep(i, 5) {
    if (c == list[i]) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;

  return 0;
}

