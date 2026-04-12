#include<iostream>
using namespace std;
int main(){

  //変数の準備
  int r, g, b;
  
  //入力
  cin >> r >> g >> b;
  
  //４の倍数かの処理
  if( (r*100 + g*10 + b)%4 == 0 ) cout << "YES" << endl;
  else  cout << "NO" << endl;

}