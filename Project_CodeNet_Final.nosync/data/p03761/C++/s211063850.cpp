#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
  int n;
  cin >> n;
  string s;
  vector<int> alpha(26, 1e9);
  REP(i,n){
    cin >> s;
    REP(j,26) alpha[j] = min(alpha[j], (int)count(s.cbegin(), s.cend(), 'a'+j));
  }
  
  REP(i,26){
    REP(j,alpha[i]) cout << (char)('a'+i);
  }
  return 0;
}