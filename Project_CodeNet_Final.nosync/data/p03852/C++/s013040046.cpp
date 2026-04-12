#include <bits/stdc++.h>
using namespace std;

int main() {
  //入力と出力用の宣言
  string A;
  char s;
  
  //初期条件
  s='E';
  A="error";
    
  //入力部
  cin >> s;
  
  //判定部
  if(s=='a'||s=='i'||s=='u'||s=='e'||s=='o'){
  	A="vowel"; 
  }
  else{
    A="consonant";
  }
  
  //出力部
  cout << A << endl;

}
