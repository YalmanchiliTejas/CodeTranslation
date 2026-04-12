#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}


int main(){
  int n;
  cin >> n;
  string s[n];
  vector<vector<int> > alph(n,vector<int>(26,0));
  rep(i,n) cin >> s[i];

  rep(i,n){
    rep(j,s[i].size()){
      alph[i][(int)(s[i][j] - 'a')] ++;
    }
  }
  int alphCnt;
  rep(i,26){
    alphCnt = 100000;
    rep(j,n){
      alphCnt = min(alph[j][i],alphCnt);
    }
    rep(k,alphCnt) cout << (char)('a' + i) ;
  }
  cout << endl;
  return 0;
}
