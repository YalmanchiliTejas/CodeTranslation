#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  string S;
  cin >> S;
  sort(ALLOF(S));

  bool flg = true;
  rep(i,S.size()){
    if(S[0] != S[i]) flg = false;
  }

  if(flg) cout << "No" << endl;
  else cout << "Yes" << endl;
    
  
  return 0;
}