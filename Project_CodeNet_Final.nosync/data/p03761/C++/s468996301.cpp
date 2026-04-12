#include <bits/stdc++.h>
using namespace std;

#define REPS(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (int i = (a); i >= n; --i)
#define DEP(i, n) DEPS(i, n, 0)

#define vint(v, n) vector<int> v(n); REP(i,n) cin >> v[i];

int main(void){

  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<string> S(n);
  REP(i, n) cin >> S[i];


  vector<int> v0(26, 50);

  static const string abet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

  REP(i, n){
    vector<int> v(26, 0);
    REP(j, S[i].length()) REP(k, 26){
      if(S[i][j] == abet[k]) v[k]++;
    }
    REP(k, 26) if(v0[k] > v[k]) v0[k] = v[k];
  }

  REP(i, 26) REP(j, v0[i]) if(v0[i] != 50) cout << abet[i];
  cout << endl;

  return 0;

}
