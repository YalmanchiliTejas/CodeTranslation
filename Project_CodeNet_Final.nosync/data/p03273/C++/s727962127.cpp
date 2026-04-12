#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;


  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<char>> a(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>a[i][j];
    }
  }
  vector<bool> b(W,false);
  vector<bool> c(H,false);
  //b
for (int j = 0; j < W; j++) {
  int flag=0;
  for(int i=0;i<H;i++){
    if(a.at(i).at(j)=='#'){flag=1;break;}
  }
  if(flag==1){
    b[j]=true;
    }
  }

for (int i = 0; i < H; i++) {
  int flag=0;
  for(int j=0;j<W;j++){
    if(a.at(i).at(j)=='#'){flag=1;break;}
  }
  if(flag==1){
    c[i]=true;
    }
  }
for(int i=0;i<H;i++){
  if(c[i]){
  for(int j=0;j<W;j++){
    if(b[j]){
      cout<<a[i][j];
    }
  }  
    cout<<endl;
  }

}
  
}
