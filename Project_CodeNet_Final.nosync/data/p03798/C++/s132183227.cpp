#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

void prts(V<char> ss) {
  REP(i, ss.size()) {
    cout << ss[i];
  }
  cout << endl;
}

int main() {
  ll k; cin >> k;
  string s; cin >> s;
  V<char> ass(s.size(), ' ');
  // 最初が羊
  ass[0] = 'S'; ass[1] = 'S';
  rep(i, 1, k-1) {
    if (ass[i] == 'S' && s[i] == 'o') {
      ass[i+1] = ass[i-1];
    } else if (ass[i]=='S' && s[i] == 'x') {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    } else if (ass[i]=='W' && s[i] == 'x') {
      ass[i+1] = ass[i-1];
    } else {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    }
  }
  if (ass[k-1]=='S') {
    if (s[k-1] == 'o') {
      if (s[0]=='o' && ass[k-2] =='S') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='o' && ass[k-2] == 'W') {
        prts(ass); return 0;
      }
    }
  } else {
    if (s[k-1] == 'o') {
      if (s[0]=='x' && ass[k-2] =='W') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='x' && ass[k-2] == 'S') {
        prts(ass); return 0;
      }
    }
  }

  REP(i, ass.size()) ass[i] = ' ';
  ass[0] = 'S'; ass[1] = 'W';
  rep(i, 1, k-1) {
    if (ass[i] == 'S' && s[i] == 'o') {
      ass[i+1] = ass[i-1];
    } else if (ass[i]=='S' && s[i] == 'x') {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    } else if (ass[i]=='W' && s[i] == 'x') {
      ass[i+1] = ass[i-1];
    } else {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    }
  }
  if (ass[k-1]=='S') {
    if (s[k-1] == 'o') {
      if (s[0]=='x' && ass[k-2] =='S') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='x' && ass[k-2] == 'W') {
        prts(ass); return 0;
      }
    }
  } else {
    if (s[k-1] == 'o') {
      if (s[0]=='o' && ass[k-2] =='W') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='o' && ass[k-2] == 'S') {
        prts(ass); return 0;
      }
    }
  }

  // 最初が狼
  REP(i, ass.size()) ass[i] = ' ';
  ass[0] = 'W'; ass[1] = 'S';
  rep(i, 1, k-1) {
    if (ass[i] == 'S' && s[i] == 'o') {
      ass[i+1] = ass[i-1];
    } else if (ass[i]=='S' && s[i] == 'x') {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    } else if (ass[i]=='W' && s[i] == 'x') {
      ass[i+1] = ass[i-1];
    } else {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    }
  }
  if (ass[k-1]=='S') {
    if (s[k-1] == 'o') {
      if (s[0]=='x' && ass[k-2] =='W') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='x' && ass[k-2] == 'S') {
        prts(ass); return 0;
      }
    }
  } else {
    if (s[k-1] == 'o') {
      if (s[0]=='o' && ass[k-2] =='S') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='o' && ass[k-2] == 'W') {
        prts(ass); return 0;
      }
    }
  }

  REP(i, ass.size()) ass[i] = ' ';
  ass[0] = 'W'; ass[1] = 'W';
  rep(i, 1, k-1) {
    if (ass[i] == 'S' && s[i] == 'o') {
      ass[i+1] = ass[i-1];
    } else if (ass[i]=='S' && s[i] == 'x') {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    } else if (ass[i]=='W' && s[i] == 'x') {
      ass[i+1] = ass[i-1];
    } else {
      if (ass[i-1] == 'S') ass[i+1] = 'W';
      else ass[i+1] = 'S';
    }
  }
  if (ass[k-1]=='S') {
    if (s[k-1] == 'o') {
      if (s[0]=='o' && ass[k-2] =='W') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='o' && ass[k-2] == 'S') {
        prts(ass); return 0;
      }
    }
  } else {
    if (s[k-1] == 'o') {
      if (s[0]=='x' && ass[k-2] =='S') {
        prts(ass); return 0;
      }
    } else {
      if (s[0]=='x' && ass[k-2] == 'W') {
        prts(ass); return 0;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
