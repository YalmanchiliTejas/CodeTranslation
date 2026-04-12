#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int H, W;
  cin >> H >> W;
  vector<string> v;
  rep(i,H){
    string s;
    cin >> s;
    v.push_back(s);
  }

  map<int,int> a, b;
  rep(i,H){
    bool flg = true;
    rep(j,W){
      if(v[i][j] == '#') flg = false;
    }
    if(flg) a[i]=1;
  }
  rep(j,W){
    bool flg = true;
    rep(i,H){
      if(v[i][j] == '#') flg = false;
    }
    if(flg) b[j]=1;
  }

  rep(i,H){
    bool flg = false;
    rep(j,W){
      if(a[i]==1 || b[j]==1) continue;
      cout << v[i][j];
      flg = true;
    }
    if(flg) cout << endl;
  }
  
  
  return 0;
}
