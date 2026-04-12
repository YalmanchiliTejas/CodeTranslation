#include<bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<string> vec(h);
  for(int i=0; i<(h); i++){
    cin >> vec[i];
  }
  
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(vec[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  
  for(int i=0; i<h; i++){
    if(row[i]){
      for(int j=0; j<w; j++){
        if(col[j]){
          cout << vec[i][j];
        }
      } 
      cout << endl;
    }
  }
}
