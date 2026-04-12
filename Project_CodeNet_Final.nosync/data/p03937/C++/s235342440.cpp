#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  char s[h+1][w+1];
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      cin >> s[i][j];
    }
  }

  int num=0;
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      if(s[i][j]=='#')++num;
    }
  }

  if(num==h+w-1){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
}

