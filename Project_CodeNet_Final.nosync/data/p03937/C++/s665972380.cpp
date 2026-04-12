#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<int>hmin(h,-1);
  vector<int>hmax(h);
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      char s;
      cin >> s;
      if(s == '#'){
        if(hmin[i] == -1) hmin[i] = j;
        hmax[i] = j;
      }
    }
  }
  for(int i = 1;i < h;i++){
    if(hmax[i-1] > hmin[i]){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
}
