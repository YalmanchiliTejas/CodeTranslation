#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int h,w;
  cin >> h >> w;
  
  char s[h][w];
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
    }
  }
  
  
  char ans[h][w];
  int flag = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '#'){
        for(int k = 0; k < w; k++){
          ans[i][k] = s[i][k];
        }
        flag = 1;
        break;
      }
    }//for
    if(flag == 0){
      for(int k = 0; k < w; k++){
         ans[i][k] = '?';
      }
    }//if
    flag = 0;
  }//for
  
  flag = 0;
  for(int i = 0; i < w; i++){
    for(int j = 0; j < h; j++){
      if(s[j][i] == '#'){
        for(int k = 0; k < h; k++){
          if(ans[k][i] != '?')
            ans[k][i] = s[k][i];
        }
        flag = 1;
        break;
      }
    }//for
    if(flag == 0){
      for(int k = 0; k < h; k++){
        ans[k][i] = '?';
      }
    }//if
    flag = 0;
  }//for
  
  flag = 0;
  rep(i,h){
    rep(j,w){
      if(ans[i][j] != '?'){
        cout << ans[i][j];
        flag = 1;
      }
    }
    if(flag == 1){
      cout << endl;
    }
    flag = 0;
  }
 
}