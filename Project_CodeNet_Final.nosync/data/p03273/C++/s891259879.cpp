#include <bits/stdc++.h>

using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  for(int i = 0; i < h; i++)cin >> v[i];
  vector<bool> r(h, false), c(w, false);
  
  for(int i = 0; i < h; i++){
  	for(int j = 0; j < w; j++){
      if(v[i][j] == '#'){
        r[i] = true;
        c[j] = true;
      }
    }
  }
  
  for(int i = 0 ; i < h; i++){
    if(r[i]){
      for(int j = 0; j < w; j++){
		if(c[j]){
          cout << v[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}