#include <iostream>
using namespace std;

int main () {
  int n, a;
  cin >> n >> a;
  char dp[n][a];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a; j++) {
      cin >> dp[i][j];  
    }  
  }
    
  // まずは横からみる
  int yoko[n];
  for (int i = 0; i < n; i++) {
    yoko[i] = 0;  
  }
  int tate[a];
  for (int i = 0; i < a; i++) {
    tate[i] = 0;  
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a; j++) {
      if (dp[i][j] == '#') {
        yoko[i] = 1;
        tate[j] = 1;
      }
    }  
  }
  int tt = 0;
  for (int i = 0; i < n; i++) {
    tt = 0;
    for (int j = 0; j < a; j++) {
      if (yoko[i] == 0 || tate[j] == 0) {  
      }  
      else {
        tt = 1;
        cout << dp[i][j];  
      }
      if (j == (a - 1) && tt == 1) {
        cout << endl;    
      }
    }  
  }
}