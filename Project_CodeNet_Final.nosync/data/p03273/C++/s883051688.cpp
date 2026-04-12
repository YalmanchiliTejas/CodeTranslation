#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++) cin >> a.at(i).at(j);
  }
  
  vector<int> cuth(0);
  vector<int> cutw(0);
  for(int i = 0; i < h; i++){
    bool ok = false;
    for(int j = 0; j < w; j++){
      if(a.at(i).at(j) == '#') ok =true;
    }
    if(!ok) cuth.push_back(i);
  }
  for(int i = 0; i < w; i++){
    bool ok = false;
    for(int j = 0; j < h; j++){
      if(a.at(j).at(i) == '#') ok = true;
    }
    if(!ok) cutw.push_back(i);
  }
  if((int)cuth.size()){
    reverse(cuth.begin(), cuth.end());
    for(int i = 0; i < h; i++){
      int k = cuth.back();
      if(k != i) continue;
      cuth.pop_back();
      for(int j = 0; j < w; j++) a.at(i).at(j) = '*';
    }
  }
  
  if((int)cutw.size()){
    reverse(cutw.begin(), cutw.end());
    for(int i = 0; i < w; i++){
      int k = cutw.back();
      if(k != i) continue;
      cutw.pop_back();
      for(int j = 0; j < h; j++) a.at(j).at(i) = '*';
    }
  }
  
  for(int i = 0; i < h; i++){
    bool ok = false;
    for(int j = 0; j < w; j++){
      char c = a.at(i).at(j);
      if(c == '*') continue;
      cout << c;
      ok = true;
    }
    if(ok) cout << endl;
  }
}