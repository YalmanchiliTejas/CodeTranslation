#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)
	//i=m -> n

int main(){
  LL h,w;
  cin >> h >> w;
  VS a(h);
  REP(i,0,h){
    cin >> a[i];
  }
  
  REP(i,0,h){
    bool white = true;
    REP(j,0,w){
      if(a[i][j] != '.'){
        white = false;
      }
    }
    if(white){
      a.erase(a.begin() + i);
      h--;
      i--;
    }
  }
  REP(j,0,w){
    bool white = true;
    REP(i,0,h){
      if(a[i][j] != '.'){
        white = false;
      }
    }
    if(white){
      REP(cnt,0,h){
        a.at(cnt).erase(a.at(cnt).begin() + j);
      }
      w--;
      j--;
    }
  }
  
  REP(i,0,h){
    cout << a[i] << endl;
  }
  
  return 0;
}
