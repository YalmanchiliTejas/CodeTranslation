#include <bits/stdc++.h>
using namespace std;
 
int main() {
  // ここにプログラムを追記
  int r,g,b;
  cin >> r >> g >> b;
  int N = 100*r+10*g+b;
  if(N%4==0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}