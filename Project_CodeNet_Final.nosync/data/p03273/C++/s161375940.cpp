#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
using namespace std;
int mod = 1e9 + 7;
template <class T>
void inputV(vector<T> &x, int n){
  for(int i=0; i<n; i++) cin >> x[i];
}

int main() {
  int h, w; cin >> h >> w;
  vector<string> a(h);
  for(int i=0; i<h; i++) cin >> a[i];

  vector<bool> ww(w, false);
  vector<bool> hh(h, false);
  for(int j=0; j<w; j++){
    bool f = true;
    for(int i=0; i<h; i++){
      if( a[i][j] == '#') f = false;
    }
    ww[j] = f;
  }
  for(int i=0; i<h; i++){
    bool f = true;
    for(int j=0; j<w; j++){
      if( a[i][j] == '#' ) f = false;
    }
    hh[i] = f;
  }

  for(int i=0; i<h; i++){
    bool f = false;
    for(int j=0; j<w; j++){
      if( ww[j] || hh[i] ) continue;
      cout << a[i][j];
      f = true;
    }
    if(f) cout << endl;
  }

  return 0;
}




//
