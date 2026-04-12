#include <bits/stdc++.h>
using namespace std;

//ベクトルが白のみか判定
bool Iswhite_v (vector<char> v){
  bool iswhite = false;
  int counter = 0;
  for(char x:v){
   if (x == '.'){
    counter++;
   }
  }
  if(v.size() == counter){
   iswhite = true; 
  }
  return iswhite;
}

//行列のj列を取り出す
vector<char> row_take(int j,vector<vector<char>> a){
  int x = a.size();
  int y = a.at(0).size();
  vector<char> r(x);
  if (j>y){
   cout << "Impossible" << endl;
    return {};
  }
  for(int i =0;i<x;i++){
   r.at(i) = a.at(i).at(j); 
  }
  return r;
}

//白のみの行の判定
bool Iswhite_l(vector<vector<char>> a){
  int x = a.size();
  int y = a.at(0).size();
  for (int i = 0 ; i <x ;i++){
    if(Iswhite_v(a.at(i))){
      return true;
    }
  }
  return false;
}

//白のみの列判定
bool Iswhite_r(vector<vector<char>> a){
  int x = a.size();
  int y = a.at(0).size();
  vector<char> row(x);
  for (int j = 0 ; j <y ;j++){
    row = row_take(j,a);
    if(Iswhite_v(row)){
      return true;
    }
  }
  return false;
}

//白のみの行を消す
vector<vector<char>> vanish_white_l(vector<vector<char>> a){
  int y = a.at(0).size();
  vector<vector<char>> b = a;
  while(Iswhite_l(b)){
   for(int i= 0;i<b.size();i++){
    if(Iswhite_v(b.at(i))){
      b.erase(b.begin()+i);
      break;
    }
   }
  }
  return b;
}

//白のみの列を消す
vector<vector<char>> vanish_white_r(vector<vector<char>> a){
  int x = a.size();
  vector<vector<char>> b = a;
  while(Iswhite_r(b)){
   for(int j= 0;j<b.at(0).size();j++){
    if(Iswhite_v(row_take(j,b))){
      for(int i = 0;i<x;i++){
       b.at(i).erase(b.at(i).begin()+j); 
      }
      break;
    }
   }
  }
  return b;
}

void mat_out( vector<vector<char>> a ){
  int x = a.size();
  int y = a.at(0).size();
  for (int i = 0;i<x;i++){
   for(int j = 0;j<y;j++){
    cout << a.at(i).at(j);
     if(j == y-1){
      cout << "" <<endl; 
     }
   }
  }
}
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> R(H,vector<char>(W));
  for(int i = 0; i<H;i++){
    for(int j = 0;j<W;j++){
     cin >> R.at(i).at(j); 
    }
  }
  while (Iswhite_r(R)||Iswhite_l(R)){
   R = vanish_white_l(R);
   R = vanish_white_r(R);
  }
  //表を表示
  mat_out(R);
}