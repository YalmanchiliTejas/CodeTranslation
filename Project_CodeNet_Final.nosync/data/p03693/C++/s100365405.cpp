#include<iostream>
using namespace std;

int main(){
  
  int R,G,B;
  
  cin >> R >> G >> B;
  
  int total = 100 * R + 10 * G + B; //カードを並べた時の数
  
  //total が 4 の倍数だったら YES,そうじゃなかったら NO
  
  if(total % 4 ==0)    cout << "YES" << endl;
  else	cout << "NO" << endl;
}