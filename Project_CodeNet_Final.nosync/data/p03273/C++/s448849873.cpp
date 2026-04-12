#include <bits/stdc++.h>
using namespace std;

bool is_empty_row(vector<char>vec){
  for (int i=0;i<vec.size();i++){
    if (vec.at(i) == '#'){
      return false;
    }
  }
  return true;
}

int main(){
  int H,W,cnt;
  cin >> H >> W;
  vector<vector<char>>A(H,vector<char>(W));
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      cin >> A.at(i).at(j);
    }
  }
  for (int j=0;j<W;j++){
    cnt = 0;
    for (int i=0;i<H;i++){
      if (A.at(i).at(j) == '#'){
        continue;
      }else{
        cnt++;
      }
    }
    if (cnt == H){
      for (int i=0;i<H;i++){
        A.at(i).at(j) = '-';
      }
    }
  }
  for (int i=0;i<H;i++){
    cnt = 0;
    for (int j=0;j<W;j++){
      if (A.at(i).at(j) == '#'){
        continue;
      }else{
        cnt++;
      }
    }
    if (cnt == W){
      for (int j=0;j<W;j++){
        A.at(i).at(j) = '-';
      }
    }
  }
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      if (A.at(i).at(j)!='-'){
        cout << A.at(i).at(j);
      }
      if (j==W-1&& !is_empty_row(A.at(i))){
        cout << endl;
      }
    }
  }
}
