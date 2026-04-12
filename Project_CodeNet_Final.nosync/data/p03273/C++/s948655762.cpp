#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int h,w; cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  bool goodx[110],goody[110];
  rep(i,110){
    goodx[i] = false;
    goody[i] = false;
  }
  
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'){
	goodx[i] = true;
	goody[j] = true;
      }
    }
  }

  rep(i,h){
    if(goodx[i]){
      rep(j,w){
	if(goody[j]){
	  cout << a[i][j];
	}
      }
      cout << endl;
    }    
  }
  
  return 0;
}
