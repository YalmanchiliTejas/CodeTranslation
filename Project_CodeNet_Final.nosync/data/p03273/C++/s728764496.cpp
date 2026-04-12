#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  int i,j;
  for(i = 0;i < h;++i){
    cin >> a.at(i);
  }
  vector<bool> yoko(h,false);
  vector<bool> tate(w,false);
  for(i = 0;i < h;++i){
    for(j = 0;j < w;++j){
      if(a.at(i).at(j) == '#'){
        yoko.at(i) = true;
        tate.at(j) = true;
      }
    }
  }
  for(i = 0;i < h;++i){
    if(yoko.at(i)){
      for(j = 0;j < w;++j){
        if(tate.at(j)){
          cout << a.at(i).at(j);
        }
      }
      cout<< endl;
    }
  }
  return 0;
}
