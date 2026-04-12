#include<bits/stdc++.h>
using namespace std;
int main(){
 int h;
  cin >> h;
  int w;
  cin >> w;
  vector<string>a(h);
  for(int i=0;i<h;++i){
    cin >> a[i];
  }
  
  vector<bool>yoko(h,false);
  vector<bool>tate(w,false);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j] == '#'){
        yoko[i] = true;
        tate[j] = true;
      }
    }
  }
  
  for(int i=0;i<h;i++){
    if(yoko[i]){
      for(int j=0;j<w;++j){
        if(tate[j]){
          cout << a[i][j] ;
        }
      }
      cout << endl;
    }
  }
}