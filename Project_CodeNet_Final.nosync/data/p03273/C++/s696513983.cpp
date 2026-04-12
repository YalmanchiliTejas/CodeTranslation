#include <bits/stdc++.h>
using namespace std;

int main(){
int H,W;
  cin>>H>>W;
  vector<string>a(H);
  for(int i=0; i<H; i++){
    cin>>a[i];}
  
  vector<bool>row(H, false), col(W, false);
  for(int i=0; i<H; i++){
   for(int j=0; j<W; j++){
    if(a[i][j]=='#'){
      row[i]=true;   // 1つでも＃があるi行はtrueにされる
      col[j]=true; } // 1つでも＃があるj列はtrueにされる
   }
  }
  
  for(int i=0; i<H; i++){
   if(row[i]){  // そのi行内に1つでも＃がある
     for(int j=0; j<W; j++){
      if(col[j]){cout<<a[i][j];} // そのj列内に1つでも＃がある
     }   // 1つだけ.があっても、それを含む行列に＃が1つでもあれば
    cout<<endl;  // 出力されるしくみ
   }
  }
  
}