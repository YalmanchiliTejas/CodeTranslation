#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++){
          cin >> data.at(i).at(j);
      }
  }


//01置換
vector<vector<int>> bit(H,vector<int>(W,0));
  for (int i = 0; i < H; i++){
      for (int j = 0; j < W; j++){
          if(data.at(i).at(j)=='#'){
              bit.at(i).at(j)=1;
          }
      }
  }

//行のチェック
  vector<int> rj(H,0);
  for (int i = 0; i < H; i++){
      for (int j = 0; j < W; j++){
          if(bit.at(i).at(j)==1){
            rj.at(i) ++;
            break;
          }
      }
  }
  int rsize =0;
  for (int i = 0; i < H; i++){
      rsize += rj.at(i);
  }
//行の圧縮
  vector<vector<int>> rbit(rsize,vector<int>(W,0));
  int k =0;
  for (int i = 0; i < H; i++){
    if(rj.at(i)==0){
    }else{
        for (int j = 0; j < W; j++){
            rbit.at(k).at(j) =bit.at(i).at(j);
        }
        k++;
    }
  } 


//列のチェック
  vector<int> cj(W,0);
  for (int i = 0; i < W; i++){
      for (int j = 0; j < H; j++){
          if(bit.at(j).at(i)==1){
            cj.at(i) ++;
            break;
          }
      }
  }
  int csize =0;
  for (int i = 0; i < W; i++){
      csize += cj.at(i);
  }
//列の圧縮
  vector<vector<int>> cbit(rsize,vector<int>(csize,0));
  int l = 0;
  for (int i = 0; i < W; i++){
    if(cj.at(i)==0){
    }else{
        for (int j = 0; j < rsize; j++){
            cbit.at(j).at(l) =rbit.at(j).at(i);
        }
        l++;
    }
  } 

//表の置換

vector<vector<char>> ans(rsize,vector<char>(csize));
  for (int i = 0; i < rsize; i++){
      for (int j = 0; j < csize; j++){
          if(cbit.at(i).at(j)==1){
              ans.at(i).at(j)='#';
          }else{
              ans.at(i).at(j)='.';
          }
      }
  }

//表の出力
    for (int i = 0; i < rsize; i++){
      for (int j = 0; j < csize; j++){
          cout << ans.at(i).at(j);
          if (j == csize-1){
              cout << endl;
            }
        }
    } 
}