#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const char NL = '\n'; 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h,w; cin >> h >> w;
  vector<string> field(h);
  REP(i,h) cin >> field[i];
  
  int cnt = 0;
  REP(i,h) REP(j,w) if(field[i][j]=='#') cnt++;
  cout << (cnt==h+w-1 ? "Possible\n" : "Impossible\n");

  return 0;
}
