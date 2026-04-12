#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  vector<int> cntm('z'-'a'+1,INF);
  REP(i, n){
    cin >> S[i];
  }
  REP(i, n){
    vector<int> cnt('z'-'a'+1, 0);
    REP(j, S[i].length()){
      cnt[S[i][j]- 'a']++;
    }
    REP(j, 'z'-'a'+1){
      cntm[j] = min(cntm[j], cnt[j]);
    }
  }

  REP(i, 'z'-'a'+1){
    REP(j, cntm[i]){
      cout << (char)('a'+i);
    }
  }
  cout << endl;
  return 0;
}
