#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> v(h, vector<char> (w));
  
  for (int i=0; i<h; i++){
    for (int j=0; j<w; j++){
      cin >> v[i][j];
    }
  }
  
 
  set<int> sh, sw;
  for (int i=0; i<h; i++){
     bool hsh = true;
    for (int j=0; j<w; j++){
      if (v[i][j] == '#'){
        hsh = false;
        break;
      }
    }
    if (hsh){
      sh.insert(i);
    }
  }
  
  
  for (int i=0; i<w; i++){
    bool wsh = true;
    for (int j=0; j<h; j++){
      if (v[j][i] == '#'){
        wsh = false;
        break;
      }
    }
    if (wsh){
      sw.insert(i);
    }
  }
  
  
  for (int i=0; i<h; i++){
    bool kaigyou = false;
    if(sh.count(i) != 0){
      continue;
    }
    for (int j=0; j<w; j++){
      if (sw.count(j) == 0){
        cout << v[i][j];
        kaigyou = true;
      }  
    }
    if(kaigyou){
      cout << endl;
    }
  }
  return 0;
}