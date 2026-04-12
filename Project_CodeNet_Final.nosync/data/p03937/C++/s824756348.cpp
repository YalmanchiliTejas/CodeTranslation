#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <random>

using namespace std;


int main() {
  int h,w;
  cin >> h >> w;
  string s[9];
  int hoge=0;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    s[i]+=".";
    for (int j = 0; j < w; j++) {
      if(s[i][j]=='#')hoge++;
    }
  }
  for (int i = 0; i < w; i++) {
    s[h]+=".";
  }
  int x=0,y=0;
  int count=0;
  do{
    if(s[x][y+1]=='#' && s[x+1][y]=='#'){
      break;
    }else if(s[x][y+1]=='#' ){
      y++;
      count++;
    }else if(s[x+1][y]=='#'){
      x++;
      count++;
    }else {
      break;
    }
  }while(1);
  if(x==(h-1) && y==(w-1) && count == (hoge-1)){
    cout << "Possible"<<endl;
  }else{
    cout << "Impossible"<<endl;
  }
  return 0;
}
