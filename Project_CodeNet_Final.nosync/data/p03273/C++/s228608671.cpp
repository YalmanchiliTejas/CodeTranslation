#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> a.at(i).at(j);
    }
  }

  vector<vector<bool>> vec_b(h, vector<bool>(w, true));
  
  for(int i=0; i<h; i++){
    bool b = false;
    for(int j=0; j<w; j++){
      if(a.at(i).at(j) == '#') b = true; 
    }
    if(!b) vec_b.at(i) = vector<bool> (w, false);
  }

  for(int i=0; i<w; i++){
    bool b = false;
    for(int j=0; j<h; j++){
      if(a.at(j).at(i) == '#') b = true; 
    }
    if(!b){
      for (int j=0; j<h; j++)
	  vec_b.at(j).at(i) = false;
    } 
  }  

  for(int i=0; i<h; i++){
    int f = 0;
    for(int j=0; j<w; j++){
      if(vec_b.at(i).at(j) == true){
        cout << a.at(i).at(j);
        f = 1;
      }
    }
	if(f == 1) cout << endl;
  }
  
  return 0;
}
