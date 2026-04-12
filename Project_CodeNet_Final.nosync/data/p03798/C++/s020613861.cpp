#include <iostream>
#include <string.h>
using namespace std;

char finish (char x) {
  if (x == 'S') {
    return 'W';  
  }  
  return 'S';
}

int main () {
  int n;
  cin >> n;
  string h;
  cin >> h;
  char box[4][2] = {
    {'S', 'S'}, {'S', 'W'}, {'W', 'S'}, {'W', 'W'}  
  };
  for (int i = 0; i < 4; i++) {
    string ans = "";
    for (int j = 0; j < n; j++) {
      ans = ans + "x";  
    }
    for (int j = 0; j < n; j++) {
      if (j < 2) {
        ans[j] = box[i][j];  
        if (j == 1) {
          if ((h[j] == 'o' && ans[j] == 'S') || 
              (h[j] == 'x' && ans[j] == 'W')) {
            ans[j + 1] = ans[j - 1];  
          }  
          else {
            ans[j + 1] = finish(ans[j - 1]);  
          }
        }
      }   
      else {
        if (j < n - 1) {
          if ((h[j] == 'o' && ans[j] == 'S') || 
              (h[j] == 'x' && ans[j] == 'W')) {
            ans[j + 1] = ans[j - 1];  
          }  
          else {
            ans[j + 1] = finish(ans[j - 1]);  
          }
        }
      }
    } 
    bool ok = false; 
    if ((h[n - 1] == 'o' && ans[n - 1] == 'S') || 
        (h[n - 1] == 'x' && ans[n - 1] == 'W')) {
      if (ans[n - 2] == ans[0]) {
        ok = true;  
      }  
    }
    else {
      if (ans[n - 2] != ans[0]) {
        ok = true;  
      }  
    }
    if ((h[0] == 'o' && ans[0] == 'S') || 
        (h[0] == 'x' && ans[0] == 'W')) {
    	if (ans[1] != ans[n - 1]) {
          ok = false;
        }
    }
    else {
      if (ans[1] == ans[n - 1]) {
        ok = false;
      }
    }
    if (ok) {
      for (int j = 0; j < n; j++) {
        cout << ans[j];    
      }  
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}