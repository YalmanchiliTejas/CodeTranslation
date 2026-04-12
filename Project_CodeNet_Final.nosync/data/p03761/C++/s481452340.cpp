#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int> (26));
  vector<string> s(n);
  
  REP(i,n){
    cin >> s[i];
    int m = s[i].size();
    REP(j,m){
      int b = s[i][j] - 'a';
      a[i][b]++;
    }
  }
  
  vector<int> cnt(26,10000);
  REP(i,n){
    REP(j,26){
      cnt[j] = min(cnt[j],a[i][j]);
    }
  }
  
  string op = "";
  REP(i,26){
    REP(j,cnt[i]){
      op += i+'a';
    }
  }

  cout << op << endl;


}