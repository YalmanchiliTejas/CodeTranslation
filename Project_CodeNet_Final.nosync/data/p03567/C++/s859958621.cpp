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

  bool flg = false;
  rep(i,S.size()-1){
    if(S[i]=='A' && S[i+1]=='C') flg = true;
  }

  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}

