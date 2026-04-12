#include<bits/stdc++.h>
using namespace std;

int h, w;

int main(void){
  cin >> h >> w;
  vector<string> a(h);
  for(int i = 0; i < h; i++) cin >> a[i];
  vector<vector<bool>> f(h, vector<bool>(w, true));
  for(int i = 0; i < h; i++){
    bool f1 = true;
    for(int j = 0; j < w; j++){
      if(a[i][j] == '#') f1 = false;
    }
    if(f1){
      for(int j = 0; j < w; j++){
        f[i][j] = false;
      }
    }
  }
  for(int j = 0; j < w; j++){
    bool f2 = true;
    for(int i = 0; i < h; i++){
      if(a[i][j] == '#') f2 = false;
    }
    if(f2){
      for(int i = 0; i < h; i++){
        f[i][j] = false;
      }
    }
  }
  vector<string> ans;
  for(int i = 0; i < h; i++){
    string s = "";
    for(int j = 0; j < w; j++){
      if(f[i][j]) s+=a[i][j];
    }
    if(s != "") ans.push_back(s);
  }
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}
