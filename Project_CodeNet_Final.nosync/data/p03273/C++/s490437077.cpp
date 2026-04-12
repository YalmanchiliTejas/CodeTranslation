#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int h,w;
  cin >> h >> w;
  
  vector<string> cont(h);
  
  for(int i = 0 ; i < h ; i++){
      cin >> cont.at(i);
  }
  
  vector<bool> a(h,false);
  vector<bool> b(w,false);
  
  for(int i = 0 ; i < h ; i++){
    for(int j = 0 ; j < w ; j++){
      if(cont.at(i).at(j) == '#'){
        a.at(i) = true;
        b.at(j) = true;
      }
    }
  }
    
    for(int i = 0 ; i < h ; i++){
      if(a.at(i)){
        for(int j = 0 ; j < w ; j++){
          if(b.at(j)){
            cout << cont.at(i).at(j);
          }
        }
        cout << endl;
      }
    }
}