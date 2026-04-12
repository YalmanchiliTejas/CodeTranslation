#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> ftable(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for (int j = 0; j < W; j++ ){
      cin >> ftable.at(i).at(j);
    }
  }
  //storeに残すべき行を溜める
  vector<int> store_1(H);
  for(int i = 0; i < H; i++){
    store_1.at(i) = 0;
  }
  int cnt = 0;
  //横列の整理
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(ftable.at(i).at(j) == '#'){
        store_1.at(cnt) = i;
        cnt++;
        break;
      }
    }
  }
  //横列を削除した後の表
  vector<vector<char>> stable(cnt, vector<char>(W));
  for(int i = 0; i < cnt; i++){
    stable.at(i) = ftable.at(store_1.at(i));
  }
  
  //横列の時と同じくstoreに溜める
  vector<int> store_2(W);
  for(int i = 0; i < W; i++){
    store_2.at(i) = 0;
  }
  
  int num = 0;
  
  //縦列の整理
  for(int i = 0; i < W; i++){
    for(int j = 0; j < cnt; j++){
      if(stable.at(j).at(i) == '#'){
        store_2.at(num) = i;
        num++;
        break;
      }
    }
  }
  
  //縦列を削除した後の表
  vector<vector<char>> res(cnt, vector<char>(num));
  for(int i = 0; i < cnt; i++){
    for(int j = 0; j < num; j++){
      cout << stable.at(i).at(store_2.at(j));
    }
    cout << endl;
  }
}
    
    
      