#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int h,w; cin >> h >> w;
  vector<string> a(h);
  for(int i = 0; i < h; i++){
    cin >> a[i];
  }

  int cnt = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j] == '#') cnt++;
    }
  }
  if(cnt == h+w-1){
    cout << "Possible" << endl;
  }else {
    cout << "Impossible" << endl;
  }

  return 0;
}
