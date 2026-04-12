#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i=0;i<h;++i){
    cin >> a[i];
  }
  vector<bool> y(h,false),t(w,false);
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(a[i][j]=='#'){
        y[i]=true;
        t[j]=true;
      }
    }
  }

  for(int i=0;i<h;++i){
    if(y[i]==true){
      for(int j=0;j<w;++j){
        if(t[j]==true) cout << a[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
