#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s[n];
  REP(i, n) cin >> s[i];

  map<char, int> mp;

  int cset[26];
  REP(i, 26) cset[i] = 55;

  REP(i, n){
    REP(j, s[i].size()) mp[s[i][j]]++;
    REP(k, 26){
      cset[k] = min(cset[k], mp['a' + k]);
      mp['a' + k] = 0;
    }
  }

  REP(i, 26){
    char q = 'a' + i;
    REP(j, cset[i]){
      cout << q;
    }
  }

}
