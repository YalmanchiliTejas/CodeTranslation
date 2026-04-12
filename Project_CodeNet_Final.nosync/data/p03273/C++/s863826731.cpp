#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m, i, j, k, l, count;
  cin >> h >> m;
  vector<vector<char>>  list(10000,vector<char>(10000));
  for(i=0;i<h;i++) {
    for(j=0;j<m;j++) {
      cin >> list.at(i).at(j);
    }
  }  
  for(i=0;i<h;i++) {
    count = 0;
    for(j=0;j<m;j++) {
      if(list.at(i).at(j) == '#') {
        count++;
      }
    }
    if(count == 0) {
      for(k=i;k<h;k++) {
        for(l=0;l<m;l++) {
          list.at(k).at(l) = list.at(k+1).at(l);
        }
      }
      h--;
      i--;
    }
  }
  
   for(i=0;i<m;i++) {
    count = 0;
    for(j=0;j<h;j++) {
      if(list.at(j).at(i) == '#') {
        count++;
      }
    }
    if(count == 0) {
      for(k=i;k<m;k++) {
        for(l=0;l<h;l++) {
          list.at(l).at(k) = list.at(l).at(k+1);
        }
      }
      m--;
      i--;
    }
  }
   for(i=0;i<h;i++) {
     for(j=0;j<m;j++) {
       cout << list.at(i).at(j);
     }
   cout << endl;
   }
  return 0;
}
     
    
        
      
    
    