#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i = 0;i<h;i++){
    cin >> a.at(i);
  }
  vector<bool> H(h,false);
  vector<bool> W(w,false);
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++){
      if( a.at(i).at(j) == '#'){
        H.at(i) = true;
        W.at(j) = true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(H.at(i) == true){
      for(int j=0;j<w;j++){
        if( W.at(j) == true){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}