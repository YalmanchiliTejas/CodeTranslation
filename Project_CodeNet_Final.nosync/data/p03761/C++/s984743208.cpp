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

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n;
vector<string> s;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) {
    string ss;
    cin >> ss;
    sort(ss.begin(), ss.end());
    s.push_back(ss);
  }

  string ss = s[0];

  FOR(i, 1, n) {
    int sl = ss.length();
    string sss = "";
    vector<bool> f(sl, true);
    REP(j, sl) {
      REP(k, s[i].length()) {
        if(ss[j] == s[i][k] && f[k]) {
          sss.push_back(ss[j]);
          f[k] = false;
          break;
        }
      }
    }
    ss = sss;
  }

  cout << ss << endl;
}
