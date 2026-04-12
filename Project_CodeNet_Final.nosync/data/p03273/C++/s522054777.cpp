#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  int H,W; cin >> H >> W;
  vector<string> a(H);
  for(int i = 0; i < H; i++){ cin >> a[i];}
  
  vector<bool> X(H); vector<bool> Y(W);
  for(int i = 0; i < H; i++){ X[i] = false;} 
  for(int j = 0; j < W; j++){ Y[j] = false;}
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(a[i][j] == '#'){ X[i] = true; Y[j] = true;}}}
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(X[i] == true && Y[j] == true){cout << a[i][j];}}
    cout << endl;}
  
  return 0;}