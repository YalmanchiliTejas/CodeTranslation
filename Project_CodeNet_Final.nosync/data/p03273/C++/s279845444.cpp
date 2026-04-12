#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chkMin(T& a, T b){
  if(a > b){
    a = b;
    return true;
  }
  return false;
}

int main() {
  int h,w;
  cin >> h >> w;
  
  vector<int> skipH;
  vector<int> skipW;  
  skipH.push_back(999);
  skipW.push_back(999);
  
  vector<vector<string>> vec(h, vector<string>(w));
  for(int i = 0; i < h; i++){
    string str;
    cin >> str;
    for(int j = 0; j < w; j++){
      vec.at(i).at(j) = str.substr(j,1);
    }
  }
  
  bool chk = true;
  for(int i = 0; i < h; i++){
    chk = true;
    for(int j = 0; j < w; j++){
      if(vec.at(i).at(j) == "#"){
        chk = false;
        break;
      }
    }
    
    if(chk == true){
      skipH.push_back(i);
    }      
  }
  
  for(int i = 0; i < w; i++){
    chk = true;
    for(int j = 0; j < h; j++){
      if(vec.at(j).at(i) == "#"){
        chk = false;
        break;
      }
    }
    
    if(chk == true){
      skipW.push_back(i);
    }
  }
    
  bool exists;
  for(int i = 0; i < h; i++){
    exists = find(skipH.begin(), skipH.end(), i) != skipH.end();
    if(exists == true){
      continue;
    }
    
    for(int j = 0; j < w; j++){
      exists = find(skipW.begin(), skipW.end(), j) != skipW.end();
      if(exists == true){
        continue;
      }
      cout << vec.at(i).at(j);
    }
    cout << endl;
  }
}
