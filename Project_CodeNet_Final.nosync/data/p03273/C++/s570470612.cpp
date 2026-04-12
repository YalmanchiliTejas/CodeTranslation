#include <bits/stdc++.h>
using namespace std;


char s[110][110];
char ans[110][110];

int main(){
  int h, w;
  cin >> h >> w;

  for(int i = 0;i < h;i++){
    cin >> s[i];
  }

  int ah = 0;
  int aw = 0;
  for(int i = 0;i < h;i++){
    int j;
    for(j = 0;j < w;j++){
      if(s[i][j] == '#'){
        break;
      }
    }
    if(j != w){
      for(j = 0;j < w;j++){
        ans[ah][j] = s[i][j];
      }
      ah++;
    }
  }

  h = ah;

  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      s[i][j] = ans[i][j];
    }
  }

  for(int j = 0;j < w;j++){
    int i;
    for(i = 0;i < h;i++){
      if(s[i][j] == '#'){
        break;
      }
    }
    if(i != h){
      for(i = 0;i < h;i++){
        ans[i][aw] = s[i][j];
      }
      aw++;
    }
  }

  w = aw;

  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}