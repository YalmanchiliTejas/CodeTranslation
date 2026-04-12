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
int n, m;
vector<int> s[10];
 
ll bfs(int a, int sum, bool c[8]) {
  if(sum >= n) return 1;
  ll ans = 0;
  REP(i, s[a].size()) {
    if(c[s[a][i]]) {
      bool c_c[10];
      memcpy(c_c, c, sizeof(c));
      c_c[s[a][i]] = false;
      ans += bfs(s[a][i], sum + 1, c_c);
    }
  }
  return ans;
}
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    s[a].push_back(b);
    s[b].push_back(a);
  }
 
  bool c[10];
  fill(c, c + n + 1, true);
  c[0] = false;
  cout << bfs(0, 1, c) << endl;
}