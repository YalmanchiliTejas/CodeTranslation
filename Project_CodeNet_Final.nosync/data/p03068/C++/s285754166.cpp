#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int nlong,klong;
  char strs[10];
    cin >> nlong;
    cin >> strs;
    cin >> klong;
    
    for (int i = 0; i < nlong; i++) {
      if(strs[i] != strs[klong-1]){
        strs[i] = '*';
      }
    }
  
   cout << strs << endl;
 
  
    
}
