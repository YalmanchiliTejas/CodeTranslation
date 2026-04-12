#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define RFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define CEIL(n, m) ceil(n/pow(10.0, m))*pow(10.0, m)
#define FLOOR(n, m) floor(n/pow(10.0, m))*pow(10.0, m)
#define ROUND(n, m) round(n/pow(10.0, m))*pow(10.0, m)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define RSORT(x) sort((x).begin(),(x).end(),greater<int>())
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define llong long long
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve()
{
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector<int> c(26, 50);
  for (int i=0; i<n; i++) {
    vector<int> dc(26, 0);
    for (auto& v : s[i]) {
      dc[v-'a']++;
    }
    for (int j=0; j<26; j++) {
      c[j] = min(c[j], dc[j]);
    }
  }

  for (int i=0; i<26; i++) {
    for (int j=0; j<c[i]; j++) {
      cout << (char)(i+'a');
    }
  }
  cout << endl;
}

int main()
{
  solve();
  return 0;
}
