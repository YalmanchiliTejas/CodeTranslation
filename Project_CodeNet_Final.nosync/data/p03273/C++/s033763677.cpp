#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];

  vector<bool> bh(h), bw(w);
  rep(i,h){
    bh[i] = [&]{
      rep(j,w) if(a[i][j]=='#') return true;
      return false;
    }();
  }
  rep(j,w){
    bw[j] = [&]{
      rep(i,h) if(a[i][j]=='#') return true;
      return false;
    }();
  }

  rep(i,h){
    if(!bh[i]) continue;
    rep(j,w) if(bw[j]) cout << a[i][j];
    cout << endl;
  }
}
