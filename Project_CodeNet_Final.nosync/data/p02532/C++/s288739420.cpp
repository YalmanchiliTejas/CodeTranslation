#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int main() {
  int n;
  cin >> n;
  stack<char> stk[n];
  string s;
  while(cin >> s) {
    if (s == "quit") break;
    if (s == "push") {
      int a; char b;
      cin >> a >> b; a--;
      stk[a].push(b);
    } else if (s == "pop") {
      int a; cin >> a; a--;
      cout << stk[a].top() << endl;
      stk[a].pop();
    } else if (s == "move") {
      int a, b;cin >> a >> b;
      a--;b--;
      int k = stk[a].top();
      stk[a].pop();
      stk[b].push(k);
    }
  }
}