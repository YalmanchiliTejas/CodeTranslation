#include <bits/stdc++.h>
using namespace std;

int main() {				
  char c;					// *constarint*
  cin >> c;					// 1 <= |S| <= 100
  							
  string vowel = "aiueo";
  // ここにプログラムを追記
  int i = 0;
  bool isVowel = false; 
  while(i < vowel.size()){
    if(vowel.at(i) == c){
      isVowel = true; 
    }
    i ++;
  }
  
  if(isVowel){
    cout << "vowel" << endl;
  }else{
  	cout << "consonant" << endl;
  }
  
}
