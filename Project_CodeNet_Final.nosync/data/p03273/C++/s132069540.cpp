#include <bits/stdc++.h>
using namespace std;

int main() {

  int h,w;
  cin >> h >> w;
  
  vector<string> data(h);
  
  for (int i=0; i<h; i++) {
    cin >> data.at(i);
  }
  
  vector<string> data2; 
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if ( data.at(i).at(j) == '#') {
        data2.push_back( data.at(i) );
        break;
      }
    }
  }
  
  vector<int> ck(w);
  for (int i=0; i<w; i++) {
     for (int j=0; j<data2.size(); j++) {
       if ( data2.at(j).at(i) == '#') {
         ck.at(i) = 1;
         break;
       }
     }
  }
  for (int i=0; i<data2.size(); i++) { 
    for (int j=0; j<w; j++) {
      if ( ck.at(j) == 1) cout << data2.at(i).at(j);
    }
    cout << endl;
  }
}
