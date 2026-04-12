#include <iostream>
#include <cstring>
using namespace std;

int t[102][102], tt[102][102];
int ans[102][102];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 0, 0, 1};

bool solve(int bit){
  memcpy(t, tt, sizeof(tt));
  memset(ans, 0, sizeof(ans));

  for(int i = 0; i < 10; i++){
    if(bit & (1 << i)){
      ans[0][i] = true;

      for(int j = 0; j < 4; j++){
        int nx = i + dx[j];
        int ny = dy[j];
        if(nx < 0 || 10 <= nx || ny < 0 || 10 <= ny) continue;
        t[ny][nx] = !t[ny][nx];
      }
    }
  }

  for(int i = 1; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(t[i - 1][j]){
        ans[i][j] = true;

        for(int k = 0; k < 4; k++){
          int nx = j + dx[k];
          int ny = i + dy[k];
          if(nx < 0 || 10 <= nx || ny < 0 || 10 <= ny) continue;
          t[ny][nx] = !t[ny][nx];
        }
      }
    }
  }

  for(int i = 0; i < 10; i++){
    if(t[9][i]){
      return false;
    }
  }

  return true;
}

int main(){
  int T;
  cin >> T;

  while(T--){
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        cin >> tt[i][j];
      }
    }

    for(int bit = 0; bit < (1 << 10); bit++){
      bool flg = solve(bit);

      if(flg){
        for(int i = 0; i < 10; i++){
          for(int j = 0; j < 10; j++){
            if(j != 0) cout << " ";
            cout << ans[i][j];
          }
          cout << endl;
        }

        break;
      }
    }
  }
}