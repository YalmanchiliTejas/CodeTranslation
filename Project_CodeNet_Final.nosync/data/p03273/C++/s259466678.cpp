#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

  int h, w;
  cin >> h >> w;

  string m[h];
  string ans[h];

  for (int i = 0; i < h; i++){
    cin >> m[i];
  }

  string s;
  string mark;
  int flag;

  int new_h = 0;

  for (int i = 0; i < h; i++){
    s = m[i];
    flag = 0;
    for (int j = 0; j < w; j++){
      mark = s[j];
      if (mark == "#"){
        flag = 1;
      }
    }
    if (flag == 1){
      ans[new_h] = s;
      new_h += 1;
    }
  }


  for (int j = w - 1; 0 <= j; j--){
    flag = 1;
    for (int i = 0; i < new_h; i++){
      mark = ans[i][j];
      if (mark == "#"){
        flag = 0;
      }
    }
    if (flag == 1){
      for (int i = 0; i < new_h; i++){
        s = ans[i];
        s.erase(s.begin()+j);
        ans[i] = s;
      }
    }
  }

  for (int i = 0; i < new_h; i++){
    cout << ans[i] << endl;
  }

  return 0;
}
