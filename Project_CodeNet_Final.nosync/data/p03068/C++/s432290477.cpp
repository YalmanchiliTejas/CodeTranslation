#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
  int n, k;

  cin >> n;
  // char s[n-1];
  //ここがダメだった
  // 最初に10だけだったんだから入れとけばよかった
  // max +ちょいくらいの範囲を持たせておく
  char s[20] = "";
  
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  
  cin >> k;
  if(k <= n){
    for(int i = 0; i < n; i++){
      if(s[i] != s[k-1]){
        s[i] = '*';
      }
    }
  }
  cout << s << endl;
  return 0;
 
}
