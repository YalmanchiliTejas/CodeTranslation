#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
//  cout << H << W << endl;
//  for(int i = 0; i < H; i++){
//    for(int j = 0; j < W; j++){
//      cout << a.at(i).at(j);
//    }
//    cout << endl;
//  }
  
  set<int> restHs;
  set<int> restWs;  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(a.at(i).at(j) == '#'){
        restHs.insert(i);
        restWs.insert(j);
      }        
  	}
  }  
  
//  for (int h : restHs) { 
//    cout << h;
//  }
//  cout << endl;
//  for (int w : restWs) { 
//    cout << w;
//  }
//  cout << endl;
  
  for (int h : restHs) {
    for (int w : restWs) { 
    	cout << a.at(h).at(w);
    }
    cout << endl;
  }
}