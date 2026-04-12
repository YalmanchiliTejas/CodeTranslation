#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
  int i, j;
  int H, W;
  cin >> H >> W;
  vector<vector<char>> array;

  vector<vector<int>> cut;
  cut.resize(2);
  cut.at(0).resize(H); // i行目削除 -> cut[0][i] = 1
  cut.at(1).resize(W); // i列目削除 -> cut[][j] = 1

  // input array's data
  array.resize(H);
  for(i=0;i<H;i++){
    array.at(i).resize(W);
    for(j=0;j<W;j++){
      cin >> array[i][j];
    }
  }

  // 行を削除
  int white;
  for(i=0;i<H;i++){
    white = 1;
    for(j=0;j<W;j++){
      if(array[i][j] == '#'){
        white = 0;
        break;
      }
    }
    if(white == 1){
      cut[0][i] = 1;
    }
  }

  // 列を削除
  for(i=0;i<W;i++){
    white = 1;
    for(j=0;j<H;j++){
      if(array[j][i] == '#'){
        white = 0;
        break;
      }
    }
    if(white == 1){
      cut[1][i] = 1;
    }
  }

  int p;
  // 出力
  for(i=0;i<H;i++){
    p = 0;
    for(j=0;j<W;j++){
      if(cut[0][i] == 0 && cut[1][j] == 0){
        cout << array[i][j];
        p = 1;
      }
    }
    if(p==1) cout << endl;
  }

  return 0;
}