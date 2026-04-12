#include <bits/stdc++.h>
using namespace std;

int main() {
  int y,x;
  cin >> y >> x;
  vector<vector<string>> a(y, vector<string>(x));
  for (int i = 0; i < y; i++) {
    string str; 
    cin >> str;
    for (int j=0; j < x; j++) {
      a.at(i).at(j) = str.at(j);
    }
  }
  
  bool n;
  
  //x軸削除
  vector<vector<string>> b;
  for (int i = 0; i < y; i++) {
  	n = false;
     for (int j = 0; j < x; j++ ) {
       if (a.at(i).at(j) == "#") {
         n = true;
         break;
       }
     }
    if (n) b.push_back(a.at(i));
  }
  
  //y軸削除
  int bsize = b.size();
  vector<string> c(bsize);

  for (int i = 0; i < x; i++) {
  	n = false;
     for (int j = 0; j < bsize; j++ ) {
       if (b.at(j).at(i) == "#") {
         n = true;
         break;
       }
     }
    if (n) {
       for (int j = 0; j < bsize; j++ ) {
         string q = b.at(j).at(i);
         c.at(j) += q;
       }
    }
  }

  for (int j = 0; j < bsize; j++ ) {
    cout << c.at(j) << endl;
  }
}