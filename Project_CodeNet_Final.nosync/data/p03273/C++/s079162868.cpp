#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  
  vector<string> s(h);
  vector<int> u(h, 0);
  vector<int> v(w, 0);
  
  for (int i = 0; i < h; i++){
    cin >> s.at(i);
  }
  
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (s.at(i).at(j) == '#'){
        u.at(i) = 1;
        v.at(j) = 1;
      }
    }
  }
  
  for (int i = 0; i < h; i++){
    if (u.at(i) == 1){
      for (int j = 0; j < w; j++){
        if (v.at(j) == 1){
          cout << s.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
  
  
    
  