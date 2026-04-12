#include <bits/stdc++.h>
using namespace std; 

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>>probe(h,vector<char>(w));
  for (int i = 0; i < h ; i++){
    for (int j = 0; j < w; j++){
      cin >> probe.at(i).at(j);
    }
  } 
  vector<bool>row(h, false);
  vector<bool>line(w, false);
    for (int i = 0; i < h ; i++){
    for (int j = 0; j < w; j++){
      if (probe.at(i).at(j) == '#'){
        row.at(i) = true;
        line.at(j) = true;
      }
    }
  }
    for (int i = 0; i < h ; i++){
      if(row.at(i)){
        for (int j = 0; j < w; j++){
          if (line.at(j)){
            cout << probe.at(i).at(j) ;
          }
        }
        cout << endl;
      }
    
            
    }
    
}
      
                          