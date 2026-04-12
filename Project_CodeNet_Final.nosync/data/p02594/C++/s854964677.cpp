//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  if(x >= 30){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}