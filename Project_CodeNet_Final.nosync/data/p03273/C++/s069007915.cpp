#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int H, W;
  int **a;
  cin >> H >> W;
  a = new int*[H];
  for (int i = 0; i < H;i++){
    a[i] = new int[W];
  }
  for (int y = 0; y < H;y++){
    for (int x = 0; x < W;x++){
      char c;
      cin >> c;
      if(c=='.'){
        a[y][x] = 0;
      }else if(c=='#'){
        a[y][x] = 1;
      }
    }
  }

  vector<int> passH, passW;
  
  // 縦探索
  for (int y = 0; y < H;y++){
    bool flag = true;

    for (int x = 0; x < W;x++){
      if(a[y][x]==1){
        flag = false;
      }
    }

    if(flag==true){
      passH.push_back(y);
    }
  }

  // 横探索
  for (int x = 0; x < W; x ++){
    bool flag = true;

    for (int y = 0; y < H; y++){
      if (a[y][x] == 1){
        flag = false;
      }
    }

    if (flag == true){
      passW.push_back(x);
    }
  }



  // 無視する行以外を出力する
  for (int y = 0; y < H;y++){
    bool passY = false;
    
    for(auto index : passH){
      if(y==index){
        passY = true;
        break;
      }
    }

    if(passY==true){
      continue;
    }

    for (int x = 0; x < W;x++){
      bool passX = false;

      for(auto index : passW){
        if(x==index){
          passX = true;
          break;
        }
      }

      if(passX==true){
        continue;
      }

      cout << (a[y][x] == 0 ? '.' : '#');
    }
    cout << endl;
  }
}
