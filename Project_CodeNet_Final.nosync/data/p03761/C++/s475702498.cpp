#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main () {
  int n;
  cin >> n;
  string h;
  vector<int> ans(26, 0);
  for (int i = 0; i < n; i++) {
    cin >> h;
    if (i == 0) {
      for (int j = 0; j < h.size(); j++) {
        ans[h[j] - 97]++;  
      }    
    }      
    else {
      vector<int> sub(26, 0);
      for (int j = 0; j < h.size(); j++) {
        sub[h[j] - 97]++;  
      }  
      for (int j = 0; j < 26; j++) {
        if (ans[j] > sub[j]) {
          ans[j] = sub[j];  
        }    
      }
    }
  }  
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < ans[i]; j++) {
      cout << char (i + 97);  
    }
  }
  cout << endl;
}