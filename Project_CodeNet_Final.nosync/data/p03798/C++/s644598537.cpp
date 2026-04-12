#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n;
string s;

bool NextA(bool now, bool be, bool ans) {
  if(now && ans) return be;
  else if(now && !ans) return !be;
  else if(!now && ans) return !be;
  else return be;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> s;

  REP(i, (1 << 2)) {
    vector<bool> c(n);
    c[0] = (i & 1);
    c[1] = (i & 1 << 1);
    bool n_a = NextA(c[0], c[1], (s[0] == 'o'));

    FOR(i, 1, n - 1) {
      c[i + 1] = NextA(c[i], c[i - 1], (s[i] == 'o'));
    }
    bool l_a = NextA(c[n - 1], c[n - 2], (s[n - 1] == 'o'));
    if(c[n - 1] == n_a && c[0] == l_a) {
      REP(i, n) cout << (c[i] ? 'S' : 'W');
      cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
