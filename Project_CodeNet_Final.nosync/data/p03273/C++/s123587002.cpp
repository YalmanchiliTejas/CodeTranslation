#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  for(int i=0; i<h; i++) cin>>a[i];
  vector<bool> r(h, false);
  vector<bool> c(w, false);
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(a[i][j] == '#') {
        r[i] = true;
        c[j] = true;
      }
    }
  }
  for(int i=0; i<h; i++){
    if(r[i]) {
      for(int j=0; j<w; j++){
        if(c[j]) cout<<a[i][j];
      }
      cout<<endl;
    }
  }
}