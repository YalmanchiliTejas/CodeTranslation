#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,K;
  cin>>N;

  // 文字列
  string str; // 文字列変数を宣言

  cin>>str; //文字(char)の列を代入
  
  cin>>K;
  
  char A;
  
  A = str.at(K-1);
  
  for (int i = 0; i < N; i++) {
   if(str.at(i) == A){
     cout << A;
   }
    else{
      cout <<"*";
    }
}
  cout << endl;
}