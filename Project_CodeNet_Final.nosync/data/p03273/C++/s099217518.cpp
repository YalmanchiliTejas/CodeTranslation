#include <bits/stdc++.h>
using namespace std;


void input(vector<vector<string>> &mas, int H){
  vector<string> str(H);
  for(int i=0;i<H;i++){
    cin >> str.at(i);
  }
  for(int i=0;i<mas.size();i++){
    for(int j=0;j<mas.at(0).size();j++){
      mas.at(i).at(j) = str.at(i).at(j);
    }
  }
}
void rawpress(vector<vector<string>> &mas, int &H, int &W){
  for(int i=0;i<H;i++){
    int count = 0;
    for(int j=0;j<W;j++){
      if(mas.at(i).at(j) == "."){
        count++;
      }
    }
    if(count==W){
      H--;
      for(int m=i;m<H;m++){
        for(int n=0;n<W;n++){
          mas.at(m).at(n) = mas.at(m+1).at(n);
        }
      }
      i--;
    }
  }
}
void colpress(vector<vector<string>> &mas, int &H, int &W){
  for(int i=0;i<W;i++){
    int count = 0;
    for(int j=0;j<H;j++){
      if(mas.at(j).at(i) == "."){
        count++;
      }
    }
    if(count==H){
      W--;
      for(int m=i;m<W;m++){
        for(int n=0;n<H;n++){
          mas.at(n).at(m) = mas.at(n).at(m+1);
        }
      }
      i--;
    }
  }
}
int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<string>> mas(H,vector<string>(W));
  input(mas,H);
  rawpress(mas,H,W);
  colpress(mas,H,W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << mas.at(i).at(j);
      if(j==W-1){
        cout << endl;
      }
    }
  }
  
}